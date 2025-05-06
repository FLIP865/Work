#include <stdio.h>
#include <math.h>

unsigned long long binet(int N);
int find_fib_n(unsigned long long F_n);
int count_even_in_fib_seq(int N);

#define bound 4000000

int main()
{
    int fib_approx_index = find_fib_n(bound);

    printf("%d %llu %d\n", fib_approx_index, binet(fib_approx_index), bound);

    int K = count_even_in_fib_seq(fib_approx_index + 1);

    printf("count %d\n", K);

    unsigned long long result = (-3 * binet(3 * (K + 1)) + binet(3 * (K + 2)) - 2) / 4;
    printf("%llu\n", result);
}

unsigned long long binet(int N)
{
    long double phi = (1.0 + sqrt(5)) / 2.0;
    
    return floor((pow(phi, N) / sqrt(5)) + 0.5);
}

int find_fib_n(unsigned long long F_n)
{
    return round(log(sqrt(5) * F_n) / log((1.0 + sqrt(5)) / 2.0));
}

int count_even_in_fib_seq(int N)
{
    if (N <= 3)
        return 0;

    double tmp = N;
    
    tmp -= 4;

    return 1 + floor(tmp / 3);
}
