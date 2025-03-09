#include <stdio.h>
#include <string.h>

const char *colors[] = {
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
};
const char *reset = "\033[0m";
size_t colors_index = 0;

int main() {
    char input[100];
    char c;

    while (fgets(input, 100, stdin)) {
        for (int i = 0; i < strlen(input); i++) {
            printf("%s%c", colors[colors_index % 6], input[i]);
            if (input[i] == '\n') {
                colors_index++;
            }
        }
    }
    printf("%s", reset);
    return 0;
}