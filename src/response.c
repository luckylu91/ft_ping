#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include "response.h"
#include "utils.h"
#include "packet.h"
#include "constants.h"
#include "libft.h"
//
#include <stdio.h>

int receive_response(int socket_fd, struct dest_info *dest, struct response_info *resp) {
    struct msghdr msg_header;
    struct iovec iov[1];
    unsigned char response_buffer[RESPONSE_BUFFER_SIZE];
    struct cmsghdr cmsg_hdr[10];
    ssize_t response_size;
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
    if (response_size != TOTAL_HEADER_SIZE + PING_PAYLOAD_SIZE) {
        return -1;
    }
    ft_bzero(resp, sizeof(struct response_info));
    ft_memcpy(&resp->ip_header, response_buffer, IP_HEADER_SIZE);
    ft_memcpy(&resp->icmp_header, response_buffer + IP_HEADER_SIZE, ICMP_HEADER_SIZE);
    ft_memcpy(&resp->data, response_buffer + TOTAL_HEADER_SIZE, PING_PAYLOAD_SIZE);

    // Payload
    // response_payload = response_buffer + TOTAL_HEADER_SIZE;

    return 0;
}

int check_response(struct icmp_packet *packet, struct response_info *response) {
    if (ft_memcmp(packet->icmp_hdr, &response->icmp_header, sizeof(struct icmphdr)) != 0)
        return -1;
    if (ft_memcmp(packet->data, response->data, PING_PAYLOAD_SIZE) != 0)
        return -1;
    size_t cs = checksum((uint16_t*)&response->ip_header, sizeof(struct iphdr), (size_t)((char*)&response->ip_header.check - (char*)&response->ip_header));
    if (cs != response->ip_header.check)
        return -1;
    cs = checksum((uint16_t*)&response->icmp_header, ICMP_HEADER_SIZE + PING_PAYLOAD_SIZE, (size_t)((char*)&response->icmp_header.checksum - (char*)&response->icmp_header));
    if (cs != response->icmp_header.checksum)
        return -1;
    return 0;
}
