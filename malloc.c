#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *a() {
    char *ret = (char*)malloc(6);
    strcpy(ret, "hello");
    return ret;
}

int main() {
    int i = 0;
    while (1) {
        char *c = a();
        if (i % 1000 == 0) printf("%s\n", c);
        free(c);
        i++;
    }
    return 0;
}
