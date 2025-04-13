#include <stdio.h>
#include <assert.h>

int states[3][5] = {{1, 1, 5, 5, 5}, 
                    {2, 2, 4, 4, 5},
                    {5, 3, 3, 3, 5}};

int main()
{
    char c = 0;
    int state = 1;
    while (scanf("%c", &c) == 1) {
        int si = c - 'a';
        if (si >= 0 && si < 3) {
            state = states[si][state - 1];
        }
    }
    if (state == 2 || state == 3 || state == 4) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}

