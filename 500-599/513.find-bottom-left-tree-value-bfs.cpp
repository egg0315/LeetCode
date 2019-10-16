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
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res = NULL;
    while (q.size()) {
      int len = q.size();
      res = q.front();
      for (int i = 0; i < len; ++i) {
        auto cur = q.front();
        q.pop();
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
    }
    return res->val;
  }
};
