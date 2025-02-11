#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
            std::vector<std::vector<int>> result;
            std::sort(nums.begin(), nums.end());
            int n = nums.size();

            for (int i = 0; i < n; i++) {
                if (i > 0 and nums[i] == nums[i - 1]) continue;

                for (int j = i + 1; j < n; j++) {
                    if (j > i + 1 and nums[j] == nums[j - 1]) continue;

                    int left = j + 1, right = n - 1;

                    while (left < right) {
                        long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                        if (sum == target) {
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});

                            while (left < right and nums[left] == nums[left + 1]) left++;
                            while (left < right and nums[right] == nums[right - 1]) right--;

                            left++;
                            right--;
                        } else if (sum < target) {
                            left++;
                        } else {
                            right--;
                        }
                    }
                }
            }
            return result;
        }
};

void print_Sum(const std::vector<std::vector<int>>& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << "\"" << result[i][j] << "\"";
            if (j != result[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i != result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution solution;

    std::vector<int> num = {2, 2, 2, 2, 2};
    int target = 8;

    std::vector<std::vector<int>> resutl = solution.fourSum(num, target);

    print_Sum(resutl);

    return 0;
}

