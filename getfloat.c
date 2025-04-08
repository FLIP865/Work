#include <stdio.h>
#include <ctype.h>

int getfloat(float *pn);
int getch(void);
void ungetch(int);

int main()
{
    float result;
    printf("Enter number: ");

    if (getfloat(&result)) {
        printf("You entered = %f\n", result);
    } else {
        printf("Wrong input!\n");
    }
    return 0;
}

int getfloat(float *pn)
{
    int c, sign;
    float power;
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
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            ungetch(signChar);
            return 0;
        }
        sign = (signChar == '-') ? -1 : 1;
    }

    *pn = 0.0;
    while (isdigit(c)) {
        *pn = 10.0 * *pn + (c - '0');
        c = getch();
    }

    if (c == '.') {
        c = getch();
        power = 1.0;

        while (isdigit(c)) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
            c = getch();
        }
        *pn = *pn / power;
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    int buf = -1;
    if (buf != -1) {
        int temp = buf;
        buf = -1;
        return temp;
    }
    return getchar();
}

void ungetch(int c)
{
    int buf = -1;
    c = buf;
}

