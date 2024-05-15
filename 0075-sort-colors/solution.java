class Solution {
  public void sortColors(int[] nums) {
    int[] frequency = new int[] {0, 0, 0};
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] == 0) {
        frequency[0]++;
      } else if (nums[i] == 1) {
        frequency[1]++;
      } else {
        frequency[2]++;
      }
    }
    int iter = 0;
    for (int i = 0; i < nums.length;) {
      if (frequency[iter] > 0) {
        nums[i] = iter;
        frequency[iter]--;
        i++;
      } else {
        iter++;
      }
    }
  }
}
