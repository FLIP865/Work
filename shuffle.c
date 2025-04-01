#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int n);
void print_shuffle(int *arr, int n);

int main() 
{
    srand(time(NULL));
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    print_shuffle(arr, n);

    shuffle(arr, n);

    printf("Shuffle array: ");
    print_shuffle(arr, n);

    return 0;
}

void shuffle(int *arr, int n)
{
    srand(time(NULL));

    for (int i = n - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);

        int tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

void print_shuffle(int *arr, int n)
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
