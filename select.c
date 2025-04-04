#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

#define STDIN 0

int main() {
    struct timeval tv;
    fd_set readfds;

    tv.tv_sec = 2;
    tv.tv_usec = 5000000;

    FD_ZERO(&readfds);
    FD_SET(STDIN, &readfds);

    select(STDIN + 1, &readfds, NULL, NULL, &tv);

    if (FD_ISSET(STDIN, &readfds)) {
        printf("A key was pressed!\n");
    } else {
        printf("Time out!\n");
    }
    return 0;
}
