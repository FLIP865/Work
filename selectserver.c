#include <asm-generic/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#define PORT "9034"
#define LOG_FILE "server.log"

FILE *log_file;

void close_server(int signo)
{
    fprintf(stderr, "\nShutting down server...\n");
    if (log_file) {
        fclose(log_file);
    }
    exit(0);
}

void log_message(const char *message)
{
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fflush(log_file);
    }
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in *)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

int main() {
    signal(SIGINT, close_server);
    log_file = fopen(LOG_FILE, "w");
    if (!log_file) {
        perror("Failed to open file!\n");
        return 1;
    }

    fd_set master, read_fds;
    int fdmax, listener, newfd;
    struct sockaddr_storage remoteaddr;
    socklen_t addrlen;
    
    char buf[257];
    int nbytes;
    char remoteIP[INET6_ADDRSTRLEN];
    int yes = 1, i, j, rv;

    struct addrinfo hints, *ai, *p;

    FD_ZERO(&master);
    FD_ZERO(&read_fds);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0) {
        fprintf(stderr,"selectserver: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = ai; p != NULL; p = p->ai_next) {
        listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (listener < 0) {
            continue;
        }

        setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
        if (bind(listener, p->ai_addr, p->ai_addrlen) < 0) {
            close(listener);
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "selectserver: failed to bind\n");
        exit(2);
    }

    freeaddrinfo(ai);

    if (listen(listener, 10) == -1) {
        perror("listen");
        exit(3);
    }

    FD_SET(listener, &master);

    fdmax = listener;

    log_message("Server started and listening...");

    for (;;) {
        read_fds = master;
        if (select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(4);
        }

        for (i = 0; i <= fdmax; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == listener) {

                    addrlen = sizeof(remoteaddr);
                    newfd = accept(listener, (struct sockaddr *)&remoteaddr, &addrlen);

                    if (newfd == -1) {
                        perror("accept");
                    } else {
                        FD_SET(newfd, &master);
                        if (newfd > fdmax) fdmax = newfd;
                        inet_ntop(remoteaddr.ss_family, get_in_addr((struct sockaddr *)&remoteaddr), remoteIP, INET6_ADDRSTRLEN);
                        char msg[256];
                        snprintf(msg, sizeof(msg), "New connection from %s on socket %d", remoteIP, newfd);
                        log_message(msg);

                        send(newfd, "Connected to server\n", 19, 0);
                    }
                } else {
                    // Оброботка данных от клиента
                    if ((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0) {
                        // Ошибка или соединение закрыто с клиентом
                        if (nbytes == 0) {
                           // соединение закрыто
                            char msg[256];
                            snprintf(msg, sizeof(msg), "Socket %d disconnected", i);
                            log_message(msg);
                        } else {
                            perror("recv");
                        }
                        close(i);
                        FD_CLR(i, &master);
                    } else {
                        buf[nbytes] = '\0';
                        
                        // Убираем лишние символы
                        char *clean_msg = strtok(buf, "\r\n");
                        char msg[256];
                        snprintf(msg, sizeof(msg), "[Client %d]: %s", i, buf);
                        log_message(msg);

                        for (j = 0; j <= fdmax; j++) {
                            if (FD_ISSET(j, &master) && j != listener && j != i) {
                                if (send(j, buf, nbytes, 0) == -1) {
                                    perror("send");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
