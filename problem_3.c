#include <stdio.h>
#include <stdlib.h>

void prime_factors(long long n, long long *largest_factor);

int main()
{
    long long number = 600851475143;
    long long largest_factor = 1;

    prime_factors(number, &largest_factor);
    printf("%lld\n", largest_factor);

    return 0;
}

void prime_factors(long long  n, long long *largest_factor)
{
    long long d = 2;
    while (n > 1) {
        if ((n % d) == 0) {
            *largest_factor = d;
            n = n / d;
        } else {
            d++;
        }
    }
}
