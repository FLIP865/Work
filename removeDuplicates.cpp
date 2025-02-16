#include <iostream>
#include <vector>

class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            if (nums.empty()) return 0;

            int k = 1;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] != nums[i - 1]) {
                    nums[k] = nums[i];
                    k++;
                }
            }
            return k;
        }
};

int main() {
    Solution solution;

    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int result = solution.removeDuplicates(nums);

    std::cout << "Result: " << result << std::endl;
    return 0;
}
