#include <stdio.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp);
int int_cmp(const void *a, const void *b);

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    int *result = (int *)cbsearch(&key, arr, n, sizeof(int), int_cmp);
    if (result) {
        printf("Element found = %d\n", *result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}

int int_cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp)
{
    int left = 0, right = num - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        void *mid_element = (char *)base + mid * size;
        int result = cmp(key, mid_element);

        if (result == 0) {
            return mid_element;
        } else if (result < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return NULL;
}
