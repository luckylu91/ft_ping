#ifndef CREATE_PACKET_H
#define CREATE_PACKET_H

#define MAX_PACKET_SIZE 65535

#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdlib.h>

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

#endif