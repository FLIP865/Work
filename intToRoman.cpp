#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iso646.h>

class Solution {
    public:
        std::string intToRoman(int num) {
            std::string roman;
            std::vector<std::string> notations = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

            for (size_t pos = 0; pos < values.size(); ++pos) {
                int count = num / values[pos];
                for (int i = 0; i < count; i++) {
                    roman += notations[pos];
                }
                num %= values[pos];
            }
            return roman;
        }
};

bool isNumber(std::string str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    int num;

    std::cout << "Enter number: ";
    while (true) {
        std::string input;
        std::cin >> input;
        if (isNumber(input)) {
            num = std::stoi(input);
            if (num > 0 and num <= 3999) {
                break;
            } else {
                std::cout << "Invalid input: ";
            }
        } else {
            std::cout << "Enter number not letter! ";
        }
    }
    
    Solution solution;
    std::cout << "Result: " << solution.intToRoman(num) << std::endl;
    return 0;
}
