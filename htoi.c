#include <complex.h>
#include <stdio.h>

#define IN 1
#define OUT 0

int htoi(char s[]);

int main() {
    char hox[] = "0x1f";
    printf("%d\n", htoi(hox));
    return 0;
}

int htoi(char s[])
{
    int i = 0, number, indigit, hexdig;
    if (s[i] == '0') {
        i++;
        if (s[i] == 'x' || s[i] == 'X') {
            i++;
        }
        indigit = IN;
        number = 0;
        for(;indigit == IN; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                hexdig = s[i] - '0';
            } else if (s[i] >= 'a' && s[i] <= 'f') {
                hexdig = s[i] - 'a' + 10;
            } else if (s[i] >= 'A' && s[i] <= 'F') {
                hexdig = s[i] - 'A' + 10;
            } else {
                indigit = OUT;
            }
            if (indigit == IN) {
                number = number * 16 + hexdig;
            }
        }
    }
    return number;
}
