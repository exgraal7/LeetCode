class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    const int n = nums.size();
    int i;
    for (i = n - 2; i >= 0; --i)
      if (nums[i] < nums[i + 1])
        break;

    if (i >= 0)
      for (int j = n - 1; j > i; --j)
        if (nums[j] > nums[i]) {
          swap(nums[i], nums[j]);
          break;
        }

    reverse(nums, i + 1, n - 1);
  }

 private:
  void reverse(vector<int>& nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]);
  }
};
