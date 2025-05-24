#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main()
{
    mpz_t n;
    char *str;
    int i;
    int sum = 0;

    mpz_init(n);
    mpz_fac_ui(n, 100);
    str = mpz_get_str(NULL, 10, n);
    for (i = 0; str[i]; i++) {
        sum += str[i] - '0';
    }
    printf("%d\n", sum);

    free(str);
    mpz_clear(n);

    return 0;
}
