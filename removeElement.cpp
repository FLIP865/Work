#include <iostream>
#include <vector>

class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val) {
            int k = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != val) {
                    nums[k] = nums[i];
                    k++;
                }
            }
            return k;
        }
};

int main() {
    Solution solution;

    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    int result = solution.removeElement(nums, val);

    std::cout << "Result: " << result << std::endl;
    return 0;
}
