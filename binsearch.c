#include <complex.h>
#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <time.h>

#define MAX 50000

int binsearch(int x, int v[], int n);
void start_stop_clock(int el, int pos);

int main() {
    int i = 0;
    int index = 10;
    int arr[MAX];
    int pos;
    int el = 12345;
    clock_t start, stop;

    for (index = 0; index < MAX; index++) {
        arr[index] = index;
    }

    start = clock();

    for (i = 0; i < 50000; i++) {
        pos = binsearch(el, arr, MAX);
    }

    stop = clock() - start;

    printf("Значение %d имеет индекс %d\n", el, pos);
    printf("Время выполнения функции %f секунд\n", (float)stop / CLOCKS_PER_SEC);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
