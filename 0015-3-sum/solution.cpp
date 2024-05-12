class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    int numElements = nums.size();
    for (int i = 0; i < numElements - 2 && nums[i] <= 0; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int j = i + 1, k = numElements - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];

        if (sum < 0) {
          ++j;
        } else if (sum > 0) {
          --k;
        } else {
          result.push_back({nums[i], nums[j], nums[k]});

          ++j;
          --k;

          while (j < k && nums[j] == nums[j - 1]) {
            ++j;
          }
          while (j < k && nums[k] == nums[k + 1]) {
            --k;
          }
        }
      }
    }

    return result;
  }
};
