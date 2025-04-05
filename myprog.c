#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print_error(const char *format, ...) {
    char buf[256];
    va_list vl;
    va_start(vl, format);
    vsprintf(buf, format, vl);
    perror(buf);
    va_end(vl);
}

int find_in_file(const char *name, int needle) {
    FILE *f;
    int count = 0;
    f = fopen(name, "r");
    if (!f) {
        print_error("Error opening file %s", name);
        abort();
    }

    for (;;) {
        int res, n;
        res = fscanf(f, "%d", &n);
        if (res == EOF)
            break;
        if (res != 1) {
            fprintf(stderr, "File %s have broken format\n", name);
            abort();
        }
        if (needle == n) 
            count++;
    }
    fclose(f);
    return count;
}

int main(int argc, char **argv)
{
    int n, i; char *endptr;
    int count = 0;
    if (argc < 3) {
        fprintf(stderr,"Ussage: %s <n> <files...>\n", argv[0]);
        return 1;
    }
    n = strtol(argv[1], &endptr, 10);
    if (endptr == argv[1]) {
        fprintf(stderr,"<%s> cannot be converted to int\n", argv[1]);
        return 1;
    }

    for (i = 2; i < argc; i++) {
        count += find_in_file(argv[i], n);
    }
    printf("%d\n", count);
}
