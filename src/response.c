#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include "utils.h"
#include "packet.h"
#include "constants.h"
#include "libft.h"

void receive_response(int socket_fd, struct dest_info *dest, struct response_info *resp) {
    struct msghdr msg_header;
    struct iovec iov[1];
    unsigned char response_buffer[50];
    struct cmsghdr cmsg_hdr[10];
    ssize_t response_size;
    struct iphdr response_ip_header;
    struct icmphdr response_icmp_header;
    // void *response_payload;

    // RECEIVE MESSAGE
    ft_bzero(&msg_header, sizeof(struct msghdr));
    ft_bzero(response_buffer, sizeof(response_buffer) / sizeof(char));
    msg_header.msg_name = &dest->addr;
    msg_header.msg_namelen = dest->addrlen;
    iov[0].iov_base = response_buffer;
    iov[0].iov_len = sizeof(response_buffer) / sizeof(char);
    msg_header.msg_iov = iov;
    msg_header.msg_iovlen = 1;
    msg_header.msg_control = cmsg_hdr;
    msg_header.msg_controllen = sizeof(cmsg_hdr) / sizeof(struct cmsghdr);

    // printf("Waiting the response...\n");
    response_size = recvmsg(
        socket_fd,
        &msg_header,
        0
    );
    if (response_size == -1)
        exit_fatal("Error in recv_msg\n");
    // IP Header
    ft_bzero(&response_ip_header, sizeof(struct iphdr));
    ft_memcpy(&response_ip_header, response_buffer, IP_HEADER_SIZE);
    resp->ttl = response_ip_header.ttl;
    // ICMP HEADER
    ft_bzero(&response_icmp_header, sizeof(struct icmphdr));
    ft_memcpy(&response_icmp_header, response_buffer + IP_HEADER_SIZE, ICMP_HEADER_SIZE);
    // Payload
    // response_payload = response_buffer + TOTAL_HEADER_SIZE;
}
