#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == target - nums[i]) {
                        return {i, j};
                    }
                }
            }
            return {};
        }
};

int main()
{
    Solution solution;

    std::vector<int> nums = {3,2,4};
    int target = 6;

    std::vector<int> result = solution.twoSum(nums,target);

    for (int index : result) {
        std::cout << "Output: (" << index << ") ";
    }
    std::cout << "\n";

    return 0;
}
