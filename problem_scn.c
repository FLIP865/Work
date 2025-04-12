#include <stdio.h>

int main()
{
    int sum = 0;
    char a;
    printf("Enter string: ");
    while (scanf("%c", &a) == 1) {
        if (a == '\n' || a == '\0') {
            break;
        }
        sum += a;
    }
    printf("%d", sum);
    return 0;
}
