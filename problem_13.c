#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>

int main()
{
    FILE *file = fopen("bignumber.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Open file!\n");
        abort();
    }

    mpz_t sum, temp;
    mpz_init(sum);
    mpz_init(temp);

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        mpz_set_str(temp, buffer, 10);
        mpz_add(sum, sum, temp);
    }
    fclose(file);

    char *sum_str = mpz_get_str(NULL, 10, sum);
    printf("First 10 number of sum %.10s\n", sum_str);

    free(sum_str);
    mpz_clear(sum);
    mpz_clear(temp);

    return 0;
}
