/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
  int diameter = 0;
  int diameterOfBinaryTree(TreeNode *root) {
    depth(root);
    return diameter;
  }
  int depth(TreeNode *root) {
    if (!root)
      return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    diameter = max(diameter, l + r);
    return max(l, r) + 1;
  }
};
