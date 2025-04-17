#include <stdio.h>

int is_prime(unsigned x);

int main()
{
    unsigned t; 
    int v0, v1, v2, v3;
    //scanf("%u", &t);

    v0 = is_prime(5);
    v1 = is_prime(7);
    v2 = is_prime(9);
    v3 = is_prime(6);

    printf("%d %d %d, %d\n", v0, v1, v2, v3);

    return 0;
}
