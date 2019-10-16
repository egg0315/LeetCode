/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    int h = height(root);
    // case1 : left subtree is full
    // case2 : right subtree is full with height h-1 and left subtree
    return height(root->right) == h - 1 ? (1 << h) + countNodes(root->right)
                                        : (1 << h - 1) + countNodes(root->left);
  }
  // complete binary tree
  int height(TreeNode *root) {
    if (!root)
      return -1;
    return height(root->left) + 1;
  }
};
