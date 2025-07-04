#include <stdio.h>
#include <math.h>

int main()
{
    double phi = (1 + sqrt(5)) / 2;
    double log_sqrt_5 = 0.5 * log10(5);
    double log_phi = log10(phi);
    int digits = 1000;
    double target = digits - 1 + log_sqrt_5;
    unsigned long long n = (unsigned long long)(target / log_phi);

    double log_f_n = n * log_phi - log_sqrt_5;
    if (log_f_n < 999) {
        n++;
    }

    printf("%llu\n", n);
    return 0;
}
