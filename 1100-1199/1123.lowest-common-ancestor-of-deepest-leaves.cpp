/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
 * tag : tree, dfs, recursion
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
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    if (!root)
      return NULL;
    int l = depth(root->left);
    int r = depth(root->right);
    if (l == r) {
      return root;
    } else if (l > r) {
      return lcaDeepestLeaves(root->left);
    }
    return lcaDeepestLeaves(root->right);
  }

  int depth(TreeNode *root) {
    if (!root)
      return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    return max(l, r) + 1;
  }
};
