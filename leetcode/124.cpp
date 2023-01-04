#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  int ans;
  int dfs(TreeNode *root) {
    if (!root) return 0;
    int l = max(dfs(root->left), 0);
    int r = max(dfs(root->right), 0);
    // with split
    ans = max(ans, l + r + root->val);
    // without split
    return max(l, r) + root->val;
  }
public:
  int maxPathSum(TreeNode *root) {
    ans = INT_MIN;
    dfs(root);
    return ans;
  }
};
