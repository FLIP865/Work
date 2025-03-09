#include <iostream>
#include <string>

const std::string colors[] = {
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
};
const std::string reset = "\033[0m";
size_t color_index = 0;

int main() {
    std::string input;
    char c;

    while (std::cin.get(c)) {
        std::cout << colors[color_index % 6] << c;
        if (c == '\n') {
            color_index++;
        }
    }
    std::cout << reset;
    return 0;
}