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
        int result = scanf("%d", &i);
        if (result == EOF) {
            printf("Input endend (EOF). Exiting program.!\n");
            return 1;
        }
        if (result == 1) {
            int c = getchar();
            if (c != '\n' && c != EOF) {
                printf("Extra characters after the number are not allowed!\n");
                while (c != '\n' && c != EOF) c = getchar();
                printf("Enter number: ");
                fflush(stdout);
                continue;
            }
            if (i > 1) {
                break;
            } else {
                printf("The number must be greater than 1!\n");
                while (c != '\n' && c != EOF) c = getchar();
                printf("Enter number: ");
                fflush(stdout);
            }
        } else {
            printf("Please enter only a number!\n");
            while (getchar() != '\n' && getchar() != EOF);
            printf("Enter number: ");
            fflush(stdout);
        }
    }
    if (isPrime(i)) {
        printf("Number (%d) is prime:\n", i);
    } else {
        printf("Number (%d) is not prime:\n", i);
    }
     return 0;
}
