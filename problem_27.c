#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int n);

int main()
{
    int max_length = 0;
    int best_a = 0;
    int best_b = 0;
    long long best_product = 0;

    for (int b = 2; b <= 1000; ++b) {
        if (!isPrime(b)) continue;
        
        for (int a = -999; a < 1000; ++a) {
            int n = 0;
            while (true) {
                long long value = (long long)n * n + (long long)a * n + b;
                if (value <= 1 || !isPrime((int)value)) break;
                ++n;
            }

            if (n > max_length) {
                max_length = n;
                best_a = a;
                best_b = b;
                best_product = (long long)a * b;
            }
        }
    }

    printf("Best odds: a = %d, b = %d\n", best_a, best_b);
    printf("The maximum length of a sequence of prime numbers: %d\n", max_length);
    printf("Work %d * %d = %lld\n", best_a, best_b, best_product);

    return 0;
}

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if ((n % 2) == 0 || ((n % 3) == 0)) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if ((n % i) == 0 || ((n % (i + 2) == 0))) return false;
    }
    return true;
}
