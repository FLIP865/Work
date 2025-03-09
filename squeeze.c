#include <stdio.h>
#define LIM 1000

void flush(char s[], int);
void squeeze(char s[], char q[]);

int main() {
    char s[LIM];
    char q[LIM], c;
    int i;

    printf("\nEnter string to squeeze: ");
    for (i = 0; i < LIM - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
    s[i] = '\0';
    printf("\nSqueeze using string: ");
    for (i = 0; i < LIM - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        q[i] = c;
    }
    q[i] = '\0';
    squeeze(s, q);
    printf("Squeezed string: %s\n", s);
    return 0;

}

void flush(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void squeeze(char s[], char q[])
{
    int i;
    for (i = 0; q[i] != '\0'; i++) {
        flush(s, q[i]);
    }
}
