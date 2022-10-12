#ifndef RESPONSE_H
#define RESPONSE_H

#include "utils.h"

void receive_response(int socket_fd, struct dest_info *dest, struct response_info *resp);

#endif // RESPONSE_H