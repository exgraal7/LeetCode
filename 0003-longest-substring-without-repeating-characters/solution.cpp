class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int i, j = 0, n = s.size(), ans = 0, cnt = 0;
    map<char, int> v;
    for (i = 0; i < n; i++) {
      if (v[s[i]] == 0) {
        v[s[i]] = 1;
        cnt++;
      } else {
        ans = max(ans, cnt);
        while (v[s[i]] == 1) {
          v[s[j]] = 0;
          j++;
          cnt--;
        }
        cnt++;
        v[s[i]] = 1;
      }
    }
    ans = max(cnt, ans);
    return ans;
  }
};
