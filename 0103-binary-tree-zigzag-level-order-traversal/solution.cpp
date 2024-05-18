class Solution {
 public:
  void zigzagLevelOrder(TreeNode *root, vector<vector<int>> &ans) {
    stack<TreeNode *> mainS;
    stack<TreeNode *> childS;
    mainS.push(root);
    int level = 1;
    vector<int> subAns;
    while (mainS.size() > 0) {
      TreeNode *front = mainS.top();
      mainS.pop();  
      subAns.push_back(front->val);
      if (level % 2 == 1) {  
        if (front->left != NULL) {
          childS.push(front->left);
        }
        if (front->right != NULL) {
          childS.push(front->right);
        }
      }

      if (level % 2 == 0) {
        if (front->right != NULL) {
          childS.push(front->right);
        }
        if (front->left != NULL) {
          childS.push(front->left);
        }
      }

      if (mainS.size() == 0) {
        swap(childS, mainS);
        ans.push_back(subAns);
        subAns.clear();
        level++;
      }
    }
  }
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL) {
      return ans;
    }

    zigzagLevelOrder(root, ans);
    return ans;
  }
};
