#include <stdio.h>

int main()
{
    unsigned s1 = 0, s2 = 0, i;

    for (i = 1; i <= 100; i++)
    {
        s1 += i * i;
        s2 += i;
    }
    printf("%u\n", s2 * s2 - s1);
    return 0;
}
