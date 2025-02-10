#include <endian.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool isPolindrome(int x) {
    if (x < 0) return false;

    int original = x;
    int64_t reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;

        if (reversed > INT32_MAX) return false;
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
