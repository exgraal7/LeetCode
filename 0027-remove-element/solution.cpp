#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; 

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};

int main() {
    Solution solution;

    std::vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = solution.removeElement(nums1, val1);
    std::cout << "Example 1: " << k1 << ", nums = [";
    for (int i = 0; i < k1; ++i) {
        std::cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;

    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = solution.removeElement(nums2, val2);
    std::cout << "Example 2: " << k2 << ", nums = [";
    for (int i = 0; i < k2; ++i) {
        std::cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;

    return 0;
}
