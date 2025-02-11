#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        std::vector<std::string> letterCombinations(std::string digits) {
            std::unordered_map<char, std::string> phoneMap = {
                {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
            };

            std::vector<std::string> result;
            std::string current;
            backtrack(digits, 0, phoneMap, current, result);
            return result;
        }

        private:
            void backtrack(const std::string &digits, int index,
                           const std::unordered_map<char, std::string> &phoneMap,
                           std::string &current, std::vector<std::string> &result) {
                if (index == digits.size()) {
                    result.push_back(current);
                    return;
                }

                char digit = digits[index];
                const std::string &letters = phoneMap.at(digit);

                for (char letter : letters) {
                    current.push_back(letter);
                    backtrack(digits, index + 1, phoneMap, current, result);
                    current.pop_back();
                }
            }
};

void print_backtrack(const std::vector<std::string>& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}


int main() {
    Solution solution;

    std::vector<std::string> result = solution.letterCombinations("33");

    print_backtrack(result);

    return 0;
}
