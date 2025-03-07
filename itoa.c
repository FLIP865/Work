#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    int n;
    char s[LEN];

    printf("Enter the number: ");
    scanf("%d", &n);
    itoa(n, s);
    printf("The number (%d) in base (%d) is (%s)\n", n, 10, s);
    return 0;
}

void itoa(int n, char s[]) {
    int i = 0, sing = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sing < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
