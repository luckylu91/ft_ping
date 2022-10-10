#include "create_packet.h"
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

void print_bits_formated(unsigned char *bytes, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (i > 0 && i % 4 == 0)
            printf("\n");
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(bytes[i]));
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");
}

void print_nbits(unsigned char *bytes, size_t start, size_t nbits) {
    size_t offset = start / 8;
    size_t i = start % 8;
    while (nbits-- != 0) {
        printf((bytes[offset] & (1 << (7-i))) ? "1" : "0");
        i++;
        if (i == 8) {
            i = 0;
            offset++;
        }
    }
    printf("\n");
}

size_t print_nbits_named( unsigned char *bytes, char *name, size_t start, size_t nbits) {
    printf("%s", name);
    print_nbits(bytes, start, nbits);
    return start + nbits;
}

int main() {
    char *payload = "ab";
    struct icmp_packet packet;

    create_echorequest_packet(1, 2, 0, &packet);

    printf("Total packet size: %lu\n", packet.packet_size);
    // size_t start = 0;
    // start = print_nbits_named((unsigned char *)&packet, "Version:             ", start, 4);
    // start = print_nbits_named((unsigned char *)&packet, "IHL:                 ", start, 4);
    // start = print_nbits_named((unsigned char *)&packet, "TOS:                 ", start, 8);
    // start = print_nbits_named((unsigned char *)&packet, "TL:                  ", start, 16);
    // start = print_nbits_named((unsigned char *)&packet, "Identification:      ", start, 16);
    // start = print_nbits_named((unsigned char *)&packet, "Flags:               ", start, 3);
    // start = print_nbits_named((unsigned char *)&packet, "Fragment Offset:     ", start, 13);
    // start = print_nbits_named((unsigned char *)&packet, "TTL:                 ", start, 8);
    // start = print_nbits_named((unsigned char *)&packet, "Protocol:            ", start, 8);
    // start = print_nbits_named((unsigned char *)&packet, "Header Checksum:     ", start, 16);
    // start = print_nbits_named((unsigned char *)&packet, "Source Address:      ", start, 32);
    // start = print_nbits_named((unsigned char *)&packet, "Destination Address: ", start, 32);
    print_bits_formated((unsigned char *)&packet, packet.packet_size);
    return 0;
}