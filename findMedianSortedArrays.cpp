#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

            int x = nums1.size(), y = nums2.size();
            int left = 0, right = x;

            while (left <= right) {
                int partitionX = (left + right) / 2;
                int partitionY = (x + y + 1) / 2 - partitionX;

                int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
                int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

                int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
                int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

                if (maxLeftX <= minRightY and maxLeftY <= minRightX) {
                    if ((x + y) % 2 == 0) {
                        return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
                    } else {
                        return std::max(maxLeftX, maxLeftY);
                    }
                } else if (maxLeftX > minRightY) {
                    right = partitionX - 1;
                } else {
                    left = partitionX + 1;
                }
            }
            throw std::runtime_error("Input arrays are not sorted");
        }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    
    std::cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << std::endl;

    std::vector<int> nums3 {1, 2};
    std::vector<int> nums4 {3, 4};
    std::cout << "Median: " << solution.findMedianSortedArrays(nums3, nums4) << std::endl;

    return 0;
}
