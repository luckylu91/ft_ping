#ifndef UTILS_H
#define UTILS_H

#define _GNU_SOURCE
#include <netdb.h>
#include <netinet/ip_icmp.h>

void exit_usage();
void exit_fatal(const char *msg);
void print_addrinfo(struct addrinfo *addrl);
void print_icmphdr(struct icmphdr *icmp_header);
void *calloc_safe(size_t size);

#endif