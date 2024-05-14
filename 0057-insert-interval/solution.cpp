class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& t) {
    int i, j, n = v.size(), a = INT_MAX, b = INT_MIN, c = 0;
    vector<vector<int>> ans;
    for (i = 0; i < n; i++) {
      if (t[1] < v[i][0]) {
        ans.push_back(t);
        for (j = i; j < n; j++) ans.push_back(v[j]);
        return ans;
      } else if (v[i][1] < t[0]) {
        ans.push_back(v[i]);
      } else {
        t[0] = min(v[i][0], t[0]);
        t[1] = max(v[i][1], t[1]);
      }
    }
    ans.push_back(t);
    return ans;
  }
};
