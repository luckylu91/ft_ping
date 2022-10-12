#ifndef RESPONSE_H
#define RESPONSE_H

#define RESPONSE_BUFFER_SIZE 84

#include "utils.h"
#include "packet.h"

struct response_info {
    struct iphdr   ip_header;
    struct icmphdr icmp_header;
    char           data[RESPONSE_BUFFER_SIZE];
};

int receive_response(int socket_fd, struct dest_info *dest, struct response_info *resp);
int check_response(struct icmp_packet *packet, struct response_info *response);

#endif // RESPONSE_H
