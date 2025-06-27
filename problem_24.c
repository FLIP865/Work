#include <stdio.h>

int indexOfNonIncreasing(int *list, int len);
void swap(int *a, int *b);
void reverse(int *list, int start, int end);
int nextPermutation(int *list, int len);
void printPermutation(int *digits, int len);

int main()
{
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = 10;
    unsigned int target = 999999;

    for (unsigned int i = 0; i < target; i++) {
        if (!nextPermutation(digits, len)) {
            printf("Not enough permutations!\n");
            return 1;
        }
    }
    printPermutation(digits, len);
    return 0;
}

int indexOfNonIncreasing(int *list, int len)
{
    int j = len - 1;
    while (j > 0 && list[j] <= list[j - 1]) {
        j--;
    }
    return j - 1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *list, int start, int end)
{
    while (start < end) {
        swap(&list[start], &list[end]);
        start++;
        end--;
    }
}

int nextPermutation(int *list, int len)
{
    int index = indexOfNonIncreasing(list, len);
    if (index == -1) {
        return 0;
    }

    int leastEle = index + 1;
    while (leastEle < len && list[leastEle] > list[index]) {
        leastEle++;
    }
    leastEle--;

    swap(&list[index], &list[leastEle]);

    reverse(list, index + 1, len - 1);

    return 1;
}

void printPermutation(int *digits, int len)
{
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", digits[i]);
    }
    printf("]\n");
}

