#include <iostream>
#include <limits>

bool isPrime(int x)
{
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i < x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    
    int i;
    std::cout << "Enter number greater than 1: " << std::flush;
    while (true) {
        if (std::cin >> i) {
            char c;
            if (std::cin.get(c) && c != '\n') {
                std::cout << "Extra characters after the number are not allowed!\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter number: " << std::flush;
                continue;
            }
            if (i > 1) {
                break;
            } else {
                std::cout << "The number must be greater than 1!\n";
                std::cout << "Enter number: " << std::flush;
                continue;
            }
        } else {
            if (std::cin.eof()) {
                std::cout << "Input ended (EOF). Exiting program.!\n";
                return 1;
            }
            std::cout << "Please enter only a number!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter number: " << std::flush;
        }
    }
    if (isPrime(i)) {
        std::cout << "Number (" << i << ") is prime:\n";
    } else {
        std::cout << "Number (" << i << ") is not prime:\n";
    }
    return 0;
}
