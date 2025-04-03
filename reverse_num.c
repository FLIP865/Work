#include <stdio.h>

void reverse(int *arr, int n);
void print_array(int *arr, int n);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    reverse(arr, n);

    printf("Revere array: ");
    print_array(arr, n);

    return 0;
}

void reverse(int *arr, int n)
{
    int i, j, temp;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_array(int *arr, int n)
{
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
