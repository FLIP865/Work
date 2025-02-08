#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            std::unordered_set<char> uniqueChar;

            int l = 0, res = 0;
            for (int r = 0; r < s.length(); r++) {
                while (uniqueChar.count(s[r])) {
                    uniqueChar.erase(s[l]);
                    l++;
                }
                uniqueChar.insert(s[r]);
                res = std::max(res, r - l + 1);
            }
            return res;
        }
};

int main() {
    std::string s;
    
    std::cout << "Enter string: ";

    std::getline(std::cin, s);

    Solution solution;

    std::cout << "Result: " << solution.lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
