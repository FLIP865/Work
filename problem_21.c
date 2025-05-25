#include <stdio.h>

long divisor_sum(long n);

int main()
{
    long i, d, sum = 0;

    for (i = 2; i < 10000; i++) {
        d = divisor_sum(i);
        if (i < d && i == divisor_sum(d)) {
            sum += i + d;
        }
    }
    printf("%ld\n", sum);

    return 0;
}

long divisor_sum(long n)
{
    long sum = 1;
    long i, k = n;

    for (i = 2; i <= k; i++) {
        long p = 1;
        while ((k % i) == 0) {
            p *= i;
            k /= i;
        }
        sum *= (p * i - 1) / (i - 1);
    }
    return sum - n;
}
