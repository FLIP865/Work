#include <stdio.h>
#include <stdbool.h>

bool isPrime(int x)
{
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++)
    {
        if ((x % i) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int i;
    printf("Enter number: ");
    while (1) {
        if (scnaf("%d", &i) != 1) {
            printf("Please enter only a number!\n");
            while (getchar() != '\n' && getchar() != EOF);
            printf("Enter number: ");
            continue;
        }
        int c = getchar();
        if (c != '\n' && c != EOF) {
            printf("Extra characters after the number are not allowed!\n");
            while (c != '\n' && c != EOF) c = getchar();
            printf("Enter number: ");
            continue;
        }
        if (i > 1) {
            break;
        } else {
            printf("The number must be greater than 1!\n");
            while (getchar() != '\n' && getchar() != EOF);
            printf("Enter number: ");
        }
    }
    if (isPrime(i)) {
        printf("Number (%d) is prime:\n", i);
    } else {
        printf("Number (%d) is not prime:\n", i);
    }
    return 0;
}

