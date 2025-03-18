#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

void cleanup(int signum)
{
    (void)signum;
    printf("Close packet\n");
    exit(0);
}

#define SERVERPORT "4950"

int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo hints, *serverinfo, *p;
    int rv;
    int numbytes;

    signal(SIGINT, cleanup);
    signal(SIGTERM, cleanup);

    if (argc != 3) {
        fprintf(stderr, "usage: talker hostname massage\n");
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &serverinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = serverinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            fprintf(stderr, "talker: socket");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "talker: failed to bind socket\n");
        freeaddrinfo(serverinfo);
        return 2;
    }
    if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0, p->ai_addr, p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        freeaddrinfo(serverinfo);
        close(sockfd);
        return 1;
    }

    printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);
    
    freeaddrinfo(serverinfo);
    close(sockfd);
    return 0;
}
