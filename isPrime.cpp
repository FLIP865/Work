#include <iostream>
#include <limits>
#include <string>
#include <sstream>

bool isPrime(int x)
{
    for (int i = 2; i * i < x; ++i)
    {
        if (x % i == 0) 
        {
            return false;
        }
    }
    return true;
}

bool isNumber(std::string& ss)
{
    std::stringstream iss(ss);
    double num;
    return (iss >> num) and iss.eof();
}

int main()
{
    int i;
    std::cout << "Enter number is greten two! ";
    while (true)
    {
        std::string input;
        std::cin >> input;
        if (isNumber(input))
        {
            i = std::stoi(input);
            if (i > 1) {
                break;
            }
        } 
        else
        {
            std::cout << "Invalid input: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if (isPrime(i))
    {
        std::cout << "Number (" << i << ") is prime:\n";
    }
    else {
        std::cout << "Number (" << i << ") is not prime:\n";
    }
    return 0;
}
