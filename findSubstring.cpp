#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    public:
        std::vector<int> findSubstring(std::string s, std::vector<std::string> words) {
            if (s.empty() || words.empty()) return {};

            int wordSize = words[0].size();
            int numWords = words.size();
            int windowSize = wordSize * numWords;
            int len = s.size();

            std::vector<int> ans;
            std::unordered_map<std::string, int> wordCount;

            for (const std::string& word : words) {
                wordCount[word]++;
            }

            for (int i = 0; i < wordSize; ++i) {
                int left = i, right = i, counts = 0;
                std::unordered_map<std::string, int> seen;

                while (right + wordSize <= len) {
                    std::string word = s.substr(right, wordSize);
                    right += wordSize;

                    if (wordCount.find(word) != wordCount.end()) {
                        seen[word]++;
                        counts++;

                        while (seen[word] > wordCount[word]) {
                            std::string leftWord = s.substr(left, wordSize);
                            left += wordSize;
                            seen[leftWord]--;
                            counts--;
                        }

                        if (counts == numWords) {
                            ans.push_back(left);
                        }
                    } else {
                        seen.clear();
                        counts = 0;
                        left = right;
                    }
                }
            }
            return ans;
        }
};

void print_str(std::vector<int>& result) {
    std::cout << "[";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution solution;
    std::string s = "barfoofoobarthefoobarman";
    std::vector<std::string> words = {"bar", "foo", "the"};

    std::vector<int> result = solution.findSubstring(s, words);

    print_str(result);
    return 0;
}
