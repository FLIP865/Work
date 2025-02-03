#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:
        int romanToInt(std::string s) {
            std::unordered_map<char, int> romanMap = {
                {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                {'C', 100}, {'D', 500}, {'M', 1000}
            };

            int result = 0;
            int prev = 0;

            for (int i = s.size() - 1; i >= 0; i--) {
                int curr = romanMap[s[i]];

                if (curr >= prev) {
                    result += curr;
                } else {
                    result -= curr;
                }
                prev = curr;
            }
            return result;
        }
};

int main() {
    std::string s;

    std::cout << "Enter string: ";
    std::getline(std::cin, s);

    Solution solution;
    std::cout << "Result: " << solution.romanToInt(s) << std::endl;
    return 0;
}
