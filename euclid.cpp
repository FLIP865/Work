#include <iostream>

int euclid_gcd(int a, int b)
{
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int x, y;

    std::cout << "Enter integer. x = ";
    std::cin >> x;
    std::cout << "Enter integer. y = ";
    std::cin >> y;

    std::cout << "GCD(x, y) = " << euclid_gcd(x, y) << std::endl;

    return 0;
}
