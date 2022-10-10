#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <strings.h>
#include "create_packet.h"
#include "utils.h"

uint16_t checksum(uint16_t *buff, size_t size, size_t word_ignored);

void create_echorequest_packet(
    uint16_t id,
    uint16_t sequence,
    size_t payload_capacity,
    struct icmp_packet *packet
) {
    if (28 + payload_capacity > MAX_PACKET_SIZE)
        exit_fatal("Maximum packet's payload size exceeded");

    bzero(packet, sizeof(struct icmp_packet));
    packet->data = calloc_safe(8 + payload_capacity);
    packet->payload = (unsigned char *)packet->data + 8;
    packet->icmp_hdr = (struct icmphdr *)packet->data;
    packet->payload_size = 0;
    packet->packet_size = 28;

    struct icmphdr *icmp_hdr = packet->icmp_hdr;
    // ip_hdr->version = 4; // IPv4
    // ip_hdr->ihl = 5; // Length of IP Header w/o options = 5 * 4 bytes
    // ip_hdr->tos = 0; // Normal priority ?
    // ip_hdr->tot_len = *packet_size;
    // ip_hdr->id = 0; // No message fragmentation, hence no identification needed ?
    // ip_hdr->frag_off = 0x4000; // Dont fragment
    // ip_hdr->ttl = MAXTTL;
    // ip_hdr->protocol = IPPROTO_UDP;
    // ip_hdr->saddr = saddr;
    // ip_hdr->daddr = daddr;
    // ip_hdr->check = checksum((uint16_t*)ip_hdr, sizeof(struct iphdr), (size_t)((uint16_t *)&ip_hdr->check - (uint16_t *)ip_hdr));

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
    bzero(packet, sizeof(struct icmp_packet));
}

// size is in bytes
uint16_t checksum(uint16_t *buff, size_t size, size_t word_ignored) {
    size_t n = size / 2;
    uint16_t checksum = 0;
    for (size_t i = 0; i < n; i++) {
        if (i == word_ignored) continue;
        checksum += buff[i];
    }
    if (size % 2 == 1) {
        checksum += ((u_int8_t *)buff)[size - 1];
    }
    return ~checksum;
}