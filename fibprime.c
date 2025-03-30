#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 256

bool isPrime(long long n);
void generate_fib_like(long long k, long long n, long long fib_seq[]);
void find_fib_primes(long long fib_seq[], long long n);

int main() {
    long long k, n;
    long long fib_seq[MAX_SIZE];
    printf("Enter number k and n: ");
    if (scanf("%lld %lld", &k, &n) != 2 || k <= 0 || n <= 0 || k >= MAX_SIZE || n >= MAX_SIZE) {
        printf("Wrong input\n");
        abort();
    }
    generate_fib_like(k, n, fib_seq);
    find_fib_primes(fib_seq, n);
    return 0;
}
bool isPrime(long long x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if ((x % 2) == 0 || ((x % 3) == 0)) return false;

    for (long long i = 5; i * i <= x; i += 6) {
        if ((x % i) == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generate_fib_like(long long k, long long n, long long fib_seq[]) {
    fib_seq[0] = 1;
    fib_seq[1] = k;

    for (long long i = 2; i < n; i++) {
        fib_seq[i] = fib_seq[i - 1] + fib_seq[i - 2];
    }

    printf("Generate Fibonacci-like sequence: [");
    for (long long i = 0; i < n; i++) {
        printf("%lld", fib_seq[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void find_fib_primes(long long fib_seq[], long long n) {
    printf("Fibonacci-like prime number: [");
    bool first = true;

    for (long long i = 0; i < n; i++) {
        if (isPrime(fib_seq[i])) {
            if (!first) {
                printf(", ");
            }
            printf("%lld", fib_seq[i]);
            first = false;
        }
    }
    printf("]\n");
}
