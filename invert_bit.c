#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void invert_bit(int32_t arr[], int size, int p);

int main() {
    int n, p;

    printf("Enter the number of elements: ");
      if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Wrong input\n");
            abort();
      }
      int32_t *arr = malloc(n * sizeof(int32_t));
      if (!arr) {
          fprintf(stderr, "Memmory alocation failed\n");
          abort();
      }

      printf("Enter %d numbers: ", n);
      for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Wrong input!\n");
            free(arr);
            abort();
        }
    }

      printf("Enter bit position to invert: ");
    if (scanf("%d", &p) != 1 || p < 1 || p > 32) {
        printf("Invalid input!\n");
        free(arr);
        abort();
    }

      invert_bit(arr, n, p);

      printf("Update array: ");
      for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
      }
      printf("\n");

      free(arr);
      return 0;
}

void invert_bit(int32_t arr[], int size, int p) {
    int mask = (1 << (p - 1));
    for (int i = 0; i < size; i++) {
        arr[i] ^= mask;
    }
}
