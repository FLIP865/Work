#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned i, j;
    size_t n = 2000000;
    unsigned long long sum = 0ULL;

    char *sieve = (char *)malloc(n * sizeof(char *));
    for (i = 2; i < n; i++) {
        if (!sieve[i]) {
            sum += i;
            for (j = i * 2; j < n; j += i) {
                sieve[j] = 1;
            }
        }
    }
    free(sieve);

    printf("%llu\n", sum);

    return 0;
}
