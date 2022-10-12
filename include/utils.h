#ifndef UTILS_H
#define UTILS_H

#include <netdb.h>
#include <netinet/ip_icmp.h>

void exit_usage();
void exit_fatal(const char *msg);
void print_addrinfo(struct addrinfo *addrl);
void print_icmphdr(struct icmphdr *icmp_header);
void *calloc_safe(size_t size);
uint16_t checksum(uint16_t *buff, size_t size, size_t word_ignored);

#define DEST_INFO_IPSTRING_BUFFSIZE 20
struct dest_info {
    char            ip_str[DEST_INFO_IPSTRING_BUFFSIZE];
    struct sockaddr addr;
    socklen_t       addrlen;
};

struct response_info {
    uint8_t ttl;
};

#endif
