#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iso646.h>

bool isNumber(const char *str) {
    if (str == NULL or *str == '\0') {
        return false;
    }
    char *endPtr;
    strtod(str, &endPtr);
    return *endPtr == '\0' and str != endPtr;
}

int print_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num;

    printf("Enter number: ");
    while (true) {
        char input[100];
        scanf("%s", input);
        if (isNumber(input)) {
            num = atof(input);
            if (num > 0) {
                break;
            } else {
                printf("Invalid input. ");
                while (getchar() != '\n');
            }
        } else {
            printf("Invalid input. Please enter number: ");
            while (getchar() != '\n');
        }
    }

    int result = print_sum(num);

    printf("Result: %d\n", result);
    return 0;
}
