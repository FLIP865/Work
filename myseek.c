#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("example.txt", "w");
    if (!f) {
        perror("Error to opening file");
        abort();
    }
    fprintf(f, "%s", "This is an apple\n");
    fseek(f, 9, SEEK_SET);
    fprintf(f, "%s", " sam");

    return 0;
}
