
/*
 * Defining _GNU_SOURCE has nothing to do with license and everything to do with writing (non-)portable code. If you define _GNU_SOURCE, you will get:
 *  - access to lots of nonstandard GNU/Linux extension functions
 *  - access to traditional functions which were omitted from the POSIX standard (often for good reason, such as being replaced with better alternatives, or being tied to particular legacy implementations)
 *  - access to low-level functions that cannot be portable, but that you sometimes need for implementing system utilities like mount, ifconfig, etc.
 *  - broken behavior for lots of POSIX-specified functions, where the GNU folks disagreed with the standards committee on how the functions should behave and decided to do their own thing.
 * As long as you're aware of these things, it should not be a problem to define _GNU_SOURCE, but you should avoid defining it and instead define _POSIX_C_SOURCE=200809L or _XOPEN_SOURCE=700 when possible to ensure that your programs are portable.
 * In particular, the things from _GNU_SOURCE that you should never use are #2 and #4 above.
 */
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "utils.h"
#include "packet.h"
#include "response.h"
#include "libft.h"

void get_dest_info(char *dest_arg, struct dest_info *dest) {
    struct addrinfo hints;
    struct addrinfo *dest_addrinfo = NULL;
    int ret;

    /* ai_family
     *        This field specifies the desired address family for the
     *        returned addresses.  Valid values for this field include
     *        AF_INET and AF_INET6.  The value AF_UNSPEC indicates that
     *        getaddrinfo() should return socket addresses for any
     *        address family (either IPv4 or IPv6, for example) that can
     *        be used with node and service.

     * ai_socktype
     *        This field specifies the preferred socket type, for
     *        example SOCK_STREAM or SOCK_DGRAM.  Specifying 0 in this
     *        field indicates that socket addresses of any type can be
     *        returned by getaddrinfo().

     * ai_protocol
     *        This field specifies the protocol for the returned socket
     *        addresses.  Specifying 0 in this field indicates that
     *        socket addresses with any protocol can be returned by
     *        getaddrinfo().

     * ai_flags
     *        This field specifies additional options, described below.
     *        Multiple flags are specified by bitwise OR-ing them
     *        together.
     */
    ft_bzero(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_protocol = SOCK_DGRAM;

    ret = getaddrinfo(
        dest_arg,
        NULL, // service (port)
        &hints,
        // NULL,
        &dest_addrinfo
    );
    if (ret != 0)
        exit_fatal(gai_strerror(ret));
    // print_addrinfo(dest_addrinfo);
    ft_bzero(dest, sizeof(struct dest_info));
    dest->addr = *dest_addrinfo->ai_addr;
    dest->addrlen = dest_addrinfo->ai_addrlen;
    inet_ntop(
        AF_INET,
        &((struct sockaddr_in*)dest_addrinfo->ai_addr)->sin_addr,
        dest->ip_str,
        DEST_INFO_IPSTRING_BUFFSIZE
    );

    print_addrinfo(dest_addrinfo);
    freeaddrinfo(dest_addrinfo);
}

int create_socket() {
    int socket_fd;
    socket_fd = socket(
        AF_INET,     // IPv4
        SOCK_RAW,    // or SOCK_DGRAM ?
        IPPROTO_ICMP // use the single available protocol
    );
    if (socket_fd == -1)
        exit_fatal("Error creating socket");
    return socket_fd;
}

void set_socket_recv_timeout(int socket_fd) {
    struct timeval timeout;

    timeout.tv_sec = PING_TIMEOUT / 1000;
    timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;
    setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval));
}

double elapsed_time_ms(struct timeval *start) {
    struct timeval stop;
    long int elapsed;

    gettimeofday(&stop, NULL);
    elapsed = (stop.tv_sec - start->tv_sec) * 1000.0;
    elapsed += (stop.tv_usec - start->tv_usec) / 1000.0;
    return elapsed;
}

void wait_for_next_send(struct timeval *last_now) {
    static double accumulated_time = 0.;

    while (accumulated_time < 2000.) {
        accumulated_time += elapsed_time_ms(last_now);
        gettimeofday(last_now, NULL);
    }
}

int main(int argc, char *argv[]) {
    int socket_fd;
    struct dest_info dest;
    struct response_info resp;
    struct timeval last_now, now;
    double rtt;
    // double accumulated_time = 0.;

    gettimeofday(&last_now, NULL);

    if (argc != 2)
        exit_usage();
    get_dest_info(argv[1], &dest);
    // CONFIGURE SOCKET
    // INTERRESTING OPTIONS
    // SO_BROADCAST:
    //   When enabled, datagram sockets are
    //   allowed to send packets to a broadcast address
    // SO_DEBUG:
    //   Enable socket debugging.  Allowed only for processes with
    //   the CAP_NET_ADMIN capability or an effective user ID of 0.
    // SO_ERROR
    //   Get and clear the pending socket error.  This socket
    //   option is read-only.  Expects an integer.
    // SO_RCVTIMEO and SO_SNDTIMEO
    //   Specify the receiving or sending timeouts until reporting
    //   an error
    socket_fd = create_socket();
    set_socket_recv_timeout(socket_fd);
    printf("PING %s (%s) %d(%d) bytes of data.\n",
        argv[1],
        dest.ip_str,
        PING_PAYLOAD,
        TOTAL_HEADER_SIZE + PING_PAYLOAD
    );

    // LOOP
    for (size_t seq_index = 0; seq_index < 3; seq_index++) {
        gettimeofday(&now, NULL);
        // wait_for_next_send(&last_now, &now);
        gettimeofday(&now, NULL);
        create_and_send_packet(socket_fd, seq_index, &dest);
        receive_response(socket_fd, &dest, &resp);
        rtt = elapsed_time_ms(&now);
        printf("%d bytes from %s: icmp_seq=%lu ttl=%d time=%.3f ms\n",
            PING_PAYLOAD + ICMP_HEADER_SIZE,
            dest.ip_str,
            seq_index + 1,
            resp.ttl,
            rtt
        );
    }

    printf("--- %s ping statistics ---", argv[1]);
    // printf("%lu packets transmitted, %lu received, %.1f%% packet loss, time %.0fms", );
}
