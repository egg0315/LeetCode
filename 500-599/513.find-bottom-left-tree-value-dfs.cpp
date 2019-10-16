/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int d, l, res;
  int findBottomLeftValue(TreeNode *root) {
    d = 0;
    l = 0;
    res = root->val;
    dfs(root, 0, 0);
    return res;
  }

  void dfs(TreeNode *root, int depth, int x) {
    if (!root)
      return;
    if (depth > d) {
      d = depth;
      res = root->val;
      l = x;
    }
    if (depth == d && x < l) {
      res = root->val;
      l = x;
    }
    dfs(root->left, depth + 1, x - 1);
    dfs(root->right, depth + 1, x + 1);
  }
};
