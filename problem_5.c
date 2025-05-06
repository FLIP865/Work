#include <stdio.h>

int main()
{
    int a = 1, b = 1, rem;
    while (b < 20) {
        rem = a % b;
        if (rem != 0) {
            a++;
            b = 1;
        }
        b++;
    }
    printf("%d\n", a);
}
