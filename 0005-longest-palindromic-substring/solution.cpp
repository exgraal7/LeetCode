class Solution {
 public:
  string pal(string &s, int len) {
    int i, j, k, n = s.size(), sz = 0;
    string ans = "";
    for (i = 0; i < n - len; i++) {
      int j = i, k = i + len, curr = 0;
      while (j >= 0 && k < n && s[j] == s[k]) {
        if (j == k)
          curr++;
        else
          curr += 2;
        j--;
        k++;
      }
      if (sz < curr) {
        sz = curr;
        ans = s.substr(j + 1, k - j - 1);
      }
    }
    return ans;
  }

  string longestPalindrome(string s) {
    string a = pal(s, 0), b = pal(s, 1);
    return (a.size() > b.size()) ? a : b;
  }
};
