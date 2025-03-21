#include <stdio.h>
#include <unistd.h>

int main() {
    int color = 91;
    for (;;)
    {
        printf("\033[%dm%s\033[0m\r", color, "hello, world");
        fflush(stdout);

        color = (color > 96) ? 91 : color + 1;

        for (int i = 0; i < 100000000; i++) {};
    }
    return 0;
}
