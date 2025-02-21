#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n) {
    unsigned int mask = ((1 << n) - 1) << (p + 1 - n);
    return x ^ mask;
}

void print_invert(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    unsigned int x = 0b11001100110011001100110011001100;
    int p = 10;
    int n = 4;

    printf("x before: ");
    print_invert(x);

    unsigned int result = invert(x, p, n);

    printf("x after:  ");
    print_invert(result);

    return 0;
}

