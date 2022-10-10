#define _GNU_SOURCE
#include <stdio.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include "utils.h"

void exit_usage() {
    printf("Command line error\n");
    printf("Usage: ./ft_ping dest\n");
    exit(1);
}

void exit_fatal(const char *msg) {
    printf("Fatal error\n");
    printf("%s\n", msg);
    exit(1);
}

void print_addrinfo(struct addrinfo *addrl) {
    int num = 0;
    for (; addrl != NULL; addrl = addrl->ai_next) {
        printf("   ---\n");
        printf("ai_flags: %d\n", addrl->ai_flags);
        printf("ai_family: %d\n", addrl->ai_family);
        printf("ai_socktype: %d\n", addrl->ai_socktype);
        printf("ai_protocol: %d\n", addrl->ai_protocol);
        printf("ai_addrlen: %u\n", addrl->ai_addrlen);
        char *ip = inet_ntoa(((struct sockaddr_in*)addrl->ai_addr)->sin_addr);
        printf("ip address: %s\n", ip);
        printf("ai_canonname: %s\n", addrl->ai_canonname);
        num++;
    }
    printf("   ---\n");
    printf("Total number of addresses: %d\n", num);
}

void print_icmphdr(struct icmphdr *icmp_header) {
    printf("ICMP header:\n");
    printf("- type: %d\n", icmp_header->type);
    printf("- code: %d\n", icmp_header->code);
    printf("- checksum: %d\n", icmp_header->checksum);
    printf("- id: %d\n", icmp_header->un.echo.id);
    printf("- sequence: %d\n", icmp_header->un.echo.sequence);
}

void *calloc_safe(size_t size) {
    void *res = calloc(size, 1);
    if (!res)
        exit_fatal("malloc error");
    return res;
}

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