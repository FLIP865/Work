#include <stdio.h>
#include <ctype.h>

int getint(int *pn);
int getch(void);
void ungetch(int);

int buf = -1;

int main() 
{
    int value;
    printf("Enter number: ");

    int result = getint(&value);

    if (result != 0) {
        printf("You entered = %d\n", value);
    } else {
        printf("Invalid input!\n");
    }
    return 0;
}

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = 1;

    if (c == '+' || c == '-') {
        int signChar = c;
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(signChar);
            return 0;
        }
        sign = (signChar == '-') ? -1 : 1;
    }

    *pn = 0;
    while (isdigit(c)) {
        *pn = 10 * *pn + (c - '0');
        c = getch();
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    if (buf != -1) {
        int temp = buf;
        buf = -1;
        return temp;
    }
    return getchar();
}

void ungetch(int c)
{
    buf = c;
}
