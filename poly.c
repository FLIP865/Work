#include <stdio.h>
#include <stdlib.h>

struct Poly {
    unsigned n;
    unsigned *p;
};

struct Poly mult(struct Poly lhs, struct Poly rhs) {
    struct Poly ret = { rhs.n + lhs.n - 1, NULL };
    ret.p = calloc(ret.n, sizeof(unsigned));
    for (int i = 0; i < lhs.n; i++) {
        for (int j = 0; j < rhs.n; j++) {
            ret.p[i + j] += lhs.p[i] * rhs.p[j];
        }
    }
    return ret;
};

void print_poly(struct Poly poly)
{
    for (unsigned i = 0; i < poly.n; i++)
    {
        if (i > 0) {
            printf(" + ");
        }
        printf("%u * x ^ %u", poly.p[i], i);
    }
    printf("\n");
}

void print_array(struct Poly arr)
{
    printf("[");
    for (unsigned i = 0; i < arr.n; i++)
    {
        if (i > 0) {
            printf(", ");
        }
        printf("%u", arr.p[i]);
    }
    printf("]\n");
}

int main()
{
    struct Poly a = {2, NULL};
    struct Poly b = {3, NULL};

    a.p = calloc(a.n, sizeof(unsigned));
    b.p = calloc(b.n, sizeof(unsigned));

    a.p[0] = 2;
    a.p[1] = 3;

    b.p[0] = 1;
    b.p[1] = 4;
    b.p[2] = 5;

    struct Poly result = mult(a, b);

    printf("Poly A: ");
    print_poly(a);

    printf("Poly B: ");
    print_poly(b);

    printf("Result: ");
    print_poly(result);

    printf("Result = ");
    print_array(result);

    free(a.p);
    free(b.p);
    free(result.p);

    return 0;
}
