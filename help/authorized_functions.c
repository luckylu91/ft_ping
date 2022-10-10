#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// Get the process ID of the calling process.
pid_t getpid(void);

// Get the real user ID of the calling process.
uid_t getuid(void);

int getaddrinfo(const char *restrict node,
                const char *restrict service,
                const struct addrinfo *restrict hints,
                struct addrinfo **restrict res);

void freeaddrinfo(struct addrinfo *res);

int gettimeofday(struct timeval *restrict tv,
                 struct timezone *restrict tz);

const char *inet_ntop(int af, const void *restrict src,
                      char *restrict dst, socklen_t size);

// inet_pton - convert IPv4 and IPv6 addresses from text to binary form
int inet_pton(int af, const char *restrict src, void *restrict dst);

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

// alarm - set an alarm clock for delivery of a signal
unsigned int alarm(unsigned int seconds);

// getsockopt, setsockopt - get and set options on sockets
int setsockopt(int sockfd, int level, int optname,
               const void *optval, socklen_t optlen);

// send, sendto, sendmsg - send a message on a socket
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen);

// socket - create an endpoint for communication
int socket(int domain, int type, int protocol);