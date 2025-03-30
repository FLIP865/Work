#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

struct sieve_t {
    int n;
    unsigned char *s;
};

void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);
void set_prime(struct sieve_t *sv, unsigned n);

int main()
{
    int cnt = 0;
    struct sieve_t sv;
    scanf("%d", &sv.n);
    sv.s = (char*)calloc(sv.n / 8, sizeof(char));
    fill_sieve(&sv);

    for (int i = 2; i <= sv.n; i++) {
        if (is_prime(&sv, i)) {
            cnt++;
        }
    }
    printf("%d\n", cnt);

    free(sv.s);
}

void set_prime(struct sieve_t *sv, unsigned n) {
    int bytenum = n / 8;
    int bitnum = n % 8;
    sv->s[bytenum] = sv->s[bytenum] | (1 << bitnum);
}

int is_prime(struct sieve_t *sv, unsigned n) {
    int bytenum = n / 8;
    int bitnum = n % 8;
    int x = (sv->s[bytenum] >> bitnum) & 1;
    return (x == 0) ? 1 : 0;
}

void fill_sieve(struct sieve_t *sv)
{
    for (int i = 2; i * i <= sv->n + 1; i++) {
        if (is_prime(sv, i)) {
            for (int j = i * i; j <= sv->n + 1; j += i) {
                set_prime(sv, j);
            }
        }
    }
}


