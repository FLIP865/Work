#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPolindrom(const std::string& ss) {
    std::string cleanedText;

    for (char c : ss) {
        if (std::tolower(c)) {
            cleanedText += std::tolower(c);
        }
    }

    std::string revers = cleanedText;
    std::reverse(revers.begin(), revers.end());
    
    return cleanedText == revers;
}

int main() {
    std::string input;

    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    if (isPolindrom(input)) {
        std::cout << "Строка является полиндромом.\n";
    } else {
        std::cout << "Строка не является полиндромом.\n";
    }
    return 0;
}
