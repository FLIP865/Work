#include <stdio.h>
#include <stdlib.h>

void print_sort(double *arr, int n);
void mergeSort(double *A, int left, int right);
void merge(double *A, int left, int mid, int right);

int main() {
    double A[] = {3, 2, 4, 5, 6, 7, 8, 9, 10,1};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    print_sort(A, n);
    printf("\n");

    mergeSort(A, 0, n - 1);

    printf("Sorted array: ");
    print_sort(A, n);

    return 0;
}

void print_sort(double *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%.0lf", arr[i]);
    }
    printf("]\n");
}

void mergeSort(double *A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

void merge(double *A, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    double *L = (double*)malloc(size1 * sizeof(double));
    double *R = (double*)malloc(size2 * sizeof(double));

    for (int i = 0; i < size1; i++) {
        L[i] = A[left + i];
    }
    for (int j = 0; j < size2; j++) {
        R[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < size2) {
        A[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

