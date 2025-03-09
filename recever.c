#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int digit = sizeof(short) * 8;
    printf("Рассчитанный диапазон signed short: %d до %d\n", -(1 << (digit - 1)), (1 << (digit - 1)) - 1);
    return 0;
}
