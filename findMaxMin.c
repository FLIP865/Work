#include <stdio.h>

void findMaxMin(int arr[], int *min, int *max, int n);

int main() 
{
    int arr[] = {1, 3, 4, 6, 9, 10};
    int min, max;
    int n = sizeof(arr) / sizeof(arr[0]);

    findMaxMin(arr, &min, &max, n);

    printf("Max = %d, Min = %d\n", max, min);

    return 0;
}

void findMaxMin(int arr[], int *min, int *max, int n)
{
    *min = arr[0], *max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min += arr[i];
        } else if (arr[i] > *max) {
            *max += arr[i];
        }
    }
}
