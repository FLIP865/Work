#include <stdio.h>
#include <sys/ucontext.h>

#define POWER 1000

int main()
{
    int digits[(POWER * 302 + 999) / 1000] = {1};
    int ndigits = 1;
    for (int i = 0; i < POWER; i++) {
        for (int n = 0, j = 0;; j++)
        {
            n += digits[j] * 2;
            digits[j] = n % 10;
            if (n >= 10)
            {
                digits[j] = n - 10;
                n = 1;
                if (j == ndigits - 1)
                    ndigits++;
            }
            else
            {
                digits[j] = n;
                if (j == ndigits - 1)
                    break;
                n = 0;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < ndigits; i++) 
        sum += digits[i];

    printf("%d\n", sum);
    return 0;
}
