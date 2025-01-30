#include <iostream>
#include <string>
#include <algorithm>

std::string reversedString(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main() {
    std::string input;

    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    std::cout << "Reversed: " << reversedString(input) << std::endl;
    return 0;
}
