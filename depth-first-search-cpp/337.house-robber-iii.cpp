/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
  unordered_map<TreeNode *, int> memo;
  int rob(TreeNode *root) {
    auto res = dfs(root);
    return max(res[0], res[1]);
  }
  // 0: not rob, 1: rob
  vector<int> dfs(TreeNode *root) {
    if (!root)
      return {0, 0};
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    vector<int> res = {0, 0};
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];
    return res;
  }
};
