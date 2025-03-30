#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
    int n;
    char *s;
};

void fill(struct sieve_t sv);

int main()
{
    int cnt = 0;
    struct sieve_t sv;
    printf("Enter number: ");
    scanf("%d", &sv.n);
    sv.s = (char*)calloc(sv.n, sizeof(char));
    fill(sv);

    for (int i = 2; i <= sv.n; i++) {
        if (sv.s[i] == 0) {
            cnt++;
        }
    }
    printf("%d\n", cnt);

    free(sv.s);
}

void fill(struct sieve_t sv)
{
    for (int i = 2; i * i <= sv.n; i++) {
        if (sv.s[i] == 0) {
            for (int j = i * i; j <= sv.n; j += i) {
                sv.s[j] = 1;
            }
        }
    }
}


