#include <stdio.h>

int bitcount(unsigned x)
{
    int b = 0;
    while (x) {
        x &= (x - 1);
        b++;
    }
    return b;
}

int main() {
    unsigned bit = 0b10000000000000000000000000001110;

    unsigned result = bitcount(bit);

    printf("Result = %u\n", result);

    return 0;
}
