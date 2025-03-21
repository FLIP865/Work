#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int iabs(int x) { return (x < 0) ? -x : x; }

int eu_mod(int x, int y) {
    int r;
    assert(y != 0);
    r = x % y;
    if (r < 0)
        r += iabs(y);
    return r;
}

int gcd(int x, int y) {
    int a, b, q;
    a = x, b = y;
    assert(y != 0);
    while (b != 0) {
        q = eu_mod(a, b);
        a = b, b = q;
    }
    return iabs(a);
}


int main() {
    int x, y, g, res;
    
    printf("Enter number: ");
    res = scanf("%d%d", &x, &y);
    if (res != 2 || y == 0) {
        printf("%s\n", "Wrong input");
        abort();
    }
    g = gcd(x, y);
    printf("%d\n", g);
    return 0;
}
