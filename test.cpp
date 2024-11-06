#include <iostream>
#include <vector>

class Solution {
    public:
        int p1 = 0, p2 = 0;

        double getMin(std::vector<int>&nums1, std::vector<int>& nums2)
        {
            if (p1 < nums1.size() and p2 < nums2.size())
            {
                return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
            }
            else if (p1 < nums1.size())
            {
                return nums1[p1++];
            }
            else if (p2 < nums2.size())
            {
                return nums2[p2++];
            }
            return -1;
        }

        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
            if ((m + n) % 2 == 0) {
                for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                    getMin(nums1, nums2);
                }
                return (double)(getMin(nums1, nums2) + getMin(nums1, nums2));
            } else {
                for (int i = 0; i < (m + n) / 2 + 1; ++i) {
                    getMin(nums1, nums2);
                }
                return getMin(nums1, nums2);
            }
            return -1;
        }
};

int main() {
    std::vector<int> nums1 = {1,3};
    std::vector<int> nums2 = {2};
    
    Solution solution;
    double result = solution.findMedianSortedArrays(nums1, nums2);

    std::cout << "Median (" << result << ") \n";
    return 0;
}
