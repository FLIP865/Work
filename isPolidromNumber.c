#include <endian.h>
#include <stdio.h>
#include <stdbool.h>

bool isPolindrome(int x) {
    if (x < 0) return false;

    int original = x, reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return original == reversed;
}

int main() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    if (isPolindrome(num)) {
        printf("true.\n");
    } else {
        printf("false.\n");
    }
    return 0;
}
