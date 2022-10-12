#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include "packet.h"
#include "utils.h"
#include "constants.h"
#include "libft.h"

#define MAX_PACKET_SIZE 65535

void create_echorequest_packet(
    uint16_t id,
    uint16_t sequence,
    size_t payload_capacity,
    struct icmp_packet *packet
) {
    if (28 + payload_capacity > MAX_PACKET_SIZE)
        exit_fatal("Maximum packet's payload size exceeded");

    ft_bzero(packet, sizeof(struct icmp_packet));
    packet->data = calloc_safe(8 + payload_capacity);
    packet->payload = (unsigned char *)packet->data + 8;
    packet->icmp_hdr = (struct icmphdr *)packet->data;
    packet->payload_size = 0;
    packet->packet_size = 28;

    struct icmphdr *icmp_hdr = packet->icmp_hdr;

    icmp_hdr->type = ICMP_ECHO; // IPv4
    // packet.type = 128; // IPv6
    icmp_hdr->code = 0;
    icmp_hdr->un.echo.id = id;
    icmp_hdr->un.echo.sequence = sequence;
    icmp_hdr->checksum = checksum(
        (uint16_t*)icmp_hdr,
        sizeof(struct iphdr),
        (size_t)((uint16_t *)&icmp_hdr->checksum - (uint16_t *)icmp_hdr)
    );
}

void free_echorequest_packet(struct icmp_packet *packet) {
    free(packet->data);
    ft_bzero(packet, sizeof(struct icmp_packet));
}

void create_and_send_packet(int socket_fd, size_t seq_index, struct dest_info *dest) {
    struct icmp_packet packet;
    ssize_t sent_size;

    create_echorequest_packet(
        (uint16_t)getpid(),
        seq_index,
        PING_PAYLOAD,
        &packet
    );
    sent_size = sendto(
        socket_fd,
        packet.data,
        packet.packet_size,
        0,
        &dest->addr,
        dest->addrlen
    );
    free_echorequest_packet(&packet);
    if (sent_size == -1)
        exit_fatal("Error in sendto");
}
