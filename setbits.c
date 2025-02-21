#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
    unsigned int mask = ((1 << n) - 1) << (p - n + 1);
    x &= ~mask;
    
    unsigned int bits_from_y = (y & ((1 << n) - 1)) << (p - n + 1);

    return x | bits_from_y;
}

void print_binary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    unsigned int x = 0b11001100110011001100110011001100;
    unsigned int y = 0b00000000000000000000000000001111;
    int p = 10;
    int n = 4;

    printf("x before: ");
    print_binary(x);

    unsigned int result = setbits(x, p, n, y);

    printf("x after:  ");
    print_binary(result);
    
    return 0;
} 
