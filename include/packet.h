#ifndef CREATE_PACKET_H
#define CREATE_PACKET_H

#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdlib.h>
#include "utils.h"

struct icmp_packet {
    // struct iphdr ip_hdr;
    struct icmphdr *icmp_hdr;
    void *data;
    void *payload;
    size_t payload_size;
    size_t packet_size;
};

void create_echorequest_packet(
    uint16_t id,
    uint16_t sequence,
    size_t payload_capacity,
    struct icmp_packet *packet
);

void free_echorequest_packet(struct icmp_packet *packet);
void create_and_send_packet(int socket_fd, size_t seq_index, struct dest_info *dest);

#endif
