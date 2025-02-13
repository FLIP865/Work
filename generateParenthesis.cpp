#include <iostream>
#include <vector>
#include <string>

class Solution {
    public:
    void backtrack(std::string current, int openParen, int closeParen, 
                   int n, std::vector<std::string>& result) {

        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        if (openParen < n) {
            backtrack(current + "(", openParen + 1, closeParen, n, result);
        }
        if (closeParen < openParen) {
            backtrack(current + ")", openParen, closeParen + 1, n, result);
        }

    }
        std::vector<std::string> generateParenthesis(int n) {
            std::vector<std::string> result;
            backtrack("", 0, 0, n, result);
            return result;
        }
};

void backtrack_print(const std::vector<std::string>& result) {
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

    int n;
    std::cout << "Enter number: ";
    std::cin >> n;

    std::vector<std::string> result = solution.generateParenthesis(n);

    backtrack_print(result);

    return 0;
}
