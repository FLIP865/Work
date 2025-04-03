#include <stdio.h>

void swap(int *v1, int *v2);
void print_array(int *arr, int n);
void selsort(int *arr, unsigned len);

int main() 
{
    int arr[] = {2, 3, 4, 5, 6, 7, 1, 9, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    selsort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
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

void swap(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void selsort(int *arr, unsigned len)
{
    for (unsigned i = 0; i < len - 1; i++)
    {
        unsigned min_index = i;
        for (unsigned j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index])
            {
                swap(&arr[j], &arr[min_index]);
            }
        }
    }
}
