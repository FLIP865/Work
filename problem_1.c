#include <stdio.h>

int main()
{
    int num = 0;
    for (int i = 0; i < 1000; i++)
    {
        if ((i % 5) == 0 || ((i % 3) == 0)) {
            num += i;
        }
    }
    printf("%d\n", num);
    return 0;
}
