#include <stdio.h>
#include <stdlib.h>

unsigned bitoperation(unsigned x) {
    return 31 - __builtin_clz(x);
}

unsigned lowest_bits(unsigned x) {
    return __builtin_ctz(x) + 1;
}

int main() {
    unsigned x;
    printf("Enter number: ");
    if (scanf("%d", &x) != 1 || x <= 0) {
        printf("Invalid input\n");
        abort();
    }

    unsigned high = bitoperation(x);
    unsigned low = lowest_bits(x);

    printf("%d %d\n", high, low);
    return 0;
}
