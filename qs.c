#include <bits/posix2_lim.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Complex {
    int real, imag;
};

int compless(const void *lhs, const void *rhs)
{
    const struct Complex *ilhs = lhs;
    const struct Complex *irhs = rhs;
    int lhsm = ilhs->real * ilhs->real + ilhs->imag * ilhs->imag;
    int rhsm = irhs->real * irhs->real + irhs->imag * irhs->imag;
    if (lhsm > rhsm) return 1;
    if (lhsm < rhsm) return -1;
    return 0;
}

int intless(const void *lhs, const void *rhs)
{
    const int *ilhs = lhs;
    const int *irhs = rhs;
    if (*ilhs > *irhs) return 1;
    if (*irhs < *ilhs) return -1;
    return 0;
}

void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", arr[i]);
    }
    printf("]\n");
}

void print_struct(struct Complex carr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("(%d, %d)", carr[i].real, carr[i].imag);
    }
    printf("]\n");
}

int main()
{
    int arr[5] = {5, 3, 1, 4, 2};
    struct Complex carr[5] = {{1, 5}, {-3, 6}, {1, 0}, {0, 0}, {10, 10}};
    qsort(arr, 5, sizeof(int), intless);
    print_array(arr, 5);

    qsort(carr, 5, sizeof(struct Complex), compless);
    print_struct(carr, 5);
    return 0;
}
