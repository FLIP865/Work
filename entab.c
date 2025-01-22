#include <stdio.h>

void entab(const char *input) {
    int position = 0;
    int space_count = 0;
    const int TABSTOB = 1;

    while (*input) {
        char c = *input++;

        if (c == ' ') {
            space_count++;
            if ((position + 1) % TABSTOB == 0) {
                putchar('\t');
                space_count = 0;
            }
            position++;
        } else {
            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }
            putchar(c);
            if (c == '\n') {
                position = 0;
            } else {
                position++;
            }
        }
    }

    while (space_count > 0) {
        putchar(' ');
        space_count--;
    }
}

int main() {
    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        entab(line);
    }
    return 0;
}
