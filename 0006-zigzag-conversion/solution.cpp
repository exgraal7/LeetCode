class Solution {
 public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;

    std::string ans;
    int cycleLength = 2 * numRows - 2;

    for (int currentRow = 1; currentRow <= numRows; ++currentRow) {
      int interval =
          (currentRow == numRows) ? cycleLength : 2 * numRows - 2 * currentRow;
      int currentIndex = currentRow - 1;

      while (currentIndex < s.length()) {
        ans.push_back(s[currentIndex]);
        currentIndex += interval;
        interval = cycleLength - interval;

        if (interval == 0) {
          interval = cycleLength;
        }
      }
    }

    return ans;
  }
};
