class Solution {
 public:
  void buildans(stack<string> &s, string &ans) {
    if (s.empty()) return;
    string mini = s.top();
    s.pop();
    buildans(s, ans);
    ans += mini;
  }
  string simplifyPath(string path) {
    stack<string> s;
    int i = 0;

    while (i < path.size()) {
      int start = i;
      int end = i + 1;
      while (end < path.size() && (path[end] != '/')) {
        end++;
      }
      i = end;
      string minipath = path.substr(start, end - start);
      if (minipath == "/" || minipath == "/.") continue;
      if (minipath != "/..")
        s.push(minipath);
      else if (!s.empty())
        s.pop();
    }
    string ans = s.empty() ? "/" : "";
    buildans(s, ans);
    return ans;
  }
};
