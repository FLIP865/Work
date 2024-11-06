#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        int threeSumClosest(std::vector<int>& nums, int target) {
            int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
            std::unordered_map<int, int> num_map;
            for (int i = 0; i < n - 2; i++)
            {
                int l = i + 1, r = n - 1;
                if (num_map.find(l) != num_map.end()) 
                {
                    return num_map[l], i;
                }
                num_map[nums[i]] = i;
            }
            return ans;
        }
};

int main()
{
    Solution solution;
    
    std::vector<int> nums3 = {0,0,0};
    int target = 1;

    int result = solution.threeSumClosest(nums3, target);

    std::cout << "Output: (" << result << ") \n";
    return 0;
}
