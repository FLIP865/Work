#include <stdio.h>
#include <string.h>
#define LEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    int n, b;
    char s[LEN];

    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Enter the base: ");
    scanf("%d", &b);
    itob(n, s, b);
    printf("The number (%d) in base (%d) is (%s)\n", n, b, s);
    return 0;
}

void itob(int n, char s[], int b) {
    int i = 0;
    do {
        int d = n % b;
        s[i++] = (d < 10) ? d + '0' : d - 10 + 'A';
    } while ((n /= b) > 0);
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}