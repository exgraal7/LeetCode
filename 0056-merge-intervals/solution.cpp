class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& v) {
    sort(v.begin(), v.end());
    int i, n = v.size(), a = 0;
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (i = 1; i < n; i++) {
      if (v[i][0] <= ans[a][1]) {
        ans[a][0] = min(ans[a][0], v[i][0]);
        ans[a][1] = max(ans[a][1], v[i][1]);
      } else
        ans.push_back(v[i]), a++;
    }
    return ans;
  }
};
