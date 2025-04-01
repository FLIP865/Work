#include <stdio.h>

void printd(int v[], int n);
void qsorts(int v[], int left, int right);
void swap(int v[], int i, int j);

int main() {
    int v[] = {9, 2, 3, 5, 6, 7, 8, 1, 4};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Original array: ");
    printd(v, n);

    printf("\n");

    qsorts(v, 0, n - 1);

    printf("Sorted array: ");
    printd(v, n);

    return 0;
}

void printd(int v[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", v[i]);
    }
    printf("]\n");
}

void qsorts(int v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsorts(v, left, last - 1);
    qsorts(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
