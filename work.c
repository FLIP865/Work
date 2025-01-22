#include <stdio.h>

const int MAXLINE = 1000;
const int WIDTH = 10;

int getstr(char s[], int maxline);
void print_wrapped(const char line[], int len, int width);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = getstr(line, MAXLINE)) > 0) {
        print_wrapped(line, len, WIDTH);
    }
    return 0;
}

void print_wrapped(const char line[], int len, int width) {
    int start = 0;
    int end = 0;

    while (start < len) {
        end = start + width;

        if (end >= len) {
            end = len;
        } else {
            while (end > start && line[end] != ' ' && line[end] != '\t') {
                --end;
            }

            if (end == start) {
                end = start + width;
            }
        }

        for (int i = start; i < end; ++i) {
            putchar(line[i]);
        }
        putchar('\n');

        while (line[end] == ' ' || line[end] == '\t') {
            ++end;
        }

        start = end;
    }
}


int getstr(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

