#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int getDivisor(int num);
bool isAbudant(int num);

int main()
{
    int *abudants = (int *)malloc(28124 * sizeof(int));
    int abudant_count = 0;
    for (int i = 1; i <= 28123; i++) {
        if (isAbudant(i)) {
            abudants[abudant_count++] = i;
        }
    }

    bool *sums = (bool *)calloc(28124, sizeof(bool));
    for (int i = 0; i < abudant_count; i++) {
        for (int j = i; j < abudant_count; j++) {
            int sum = abudants[i] + abudants[j];
            if (sum <= 28123) {
                sums[sum] = true;
            } else {
                break;
            }
        }
    }

    long long total = 0;
    for (int i = 1; i <= 28123; i++) {
        if (!sums[i]) {
            total += i;
        }
    }
    printf("%lld\n", total);

    free(abudants);
    free(sums);

    return 0;
}

int getDivisor(int num)
{
    if (num <= 1) return 0;
    int total = 1;
    int sqrt_num = (int)sqrt(num);
    for (int divisor = 2; divisor <= sqrt_num; divisor++) {
        if ((num % divisor) == 0) {
            total += divisor;
            if (divisor != num / divisor) {
                total += num / divisor;
            }
        }
    }
    return total;
}

bool isAbudant(int num)
{
    return getDivisor(num) > num;
}
