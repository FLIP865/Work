#include <stdio.h>

int is_polindrome(int n);


int main()
{
    int max_palindrome = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product <= max_palindrome) {
                continue;
            }
            if (is_polindrome(product)) {
                max_palindrome = product;
            }
        }
    }
    printf("%d\n", max_palindrome);
    return 0;
}

int is_polindrome(int n)
{
    int revers = 0, temp = n;
    while (temp > 0) {
        revers = revers * 10 + temp % 10;
        temp /= 10;
    }
    return n == revers;
}
