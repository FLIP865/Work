#include <iostream>
#include <vector>

class Solution {
    public:
        bool canSortArray(std::vector<int>& nums) {
            int n = nums.size();
            std::vector<int> value = nums;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (value[j] <= value[j + 1]) {
                        continue;
                    } else {
                        if (__builtin_popcount(nums[j]) ==
                            __builtin_popcount(nums[j + 1])) {
                            std::swap(value[j], value[j + 1]);
                        } else {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
};

int main() {

    Solution solution;
    std::vector<int> nums = {8,4,2,30,15};

    bool result = solution.canSortArray(nums);
    
    if (result) {
        std::cout << "Output:\n";
    } else {
        std::cout << "false:\n";
    }

    return 0;
}

