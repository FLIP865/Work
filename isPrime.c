#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Переоброзование строки в число
bool isNumber(const char *str) {
    if (str == NULL || *str == '\0') {
        return false;
    }
    char *expr;
    strtod(str, &expr);
    return *expr == '\0' && str != expr;
}

bool isPrime(int x)
{
    for (int i = 2; i*i <= x; i++)
    {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int i = 0;
    printf("Enter number: ");
    while (1) {
        char input[100];
        scanf("%s", input);
        if (isNumber(input)) {
            i = atof(input);
            if (i > 1) {
                break;
            } else {
                printf("Invalid input: ");
                while (getchar() != '\n');
            }
        } else {
            printf("Please enter leatters! ");
            while(getchar() != '\n');
        }
    }

    if (isPrime(i)) {
        printf("Number (%d) is prime:\n", i);
    } else {
        printf("Number (%d) is not prime:\n", i);
    }
    return 0;
}

