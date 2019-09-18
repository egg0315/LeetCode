/*
 * @lc app=leetcode id=545 lang=cpp
 *
 * [545] Boundary of Binary Tree
 *
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
// there is a one pass solution
class Solution {
public:
  vector<int> boundaryOfBinaryTree(TreeNode *root) {
    if (!root)
      return {};
    vector<int> v = {root->val};
    if (!root->left && !root->right)
      return v;
    getLeft(root->left, v); // pre-order
    getLeaves(root, v);
    getRight(root->right, v); // post-order
    return v;
  }

  void getLeft(TreeNode *root, vector<int> &v) {
    if (!root)
      return;
    if (!root->left && !root->right)
      return;
    v.push_back(root->val);
    if (!root->left) {
      getLeft(root->right, v);
    } else {
      getLeft(root->left, v);
    }
  }

  void getRight(TreeNode *root, vector<int> &v) {
    if (!root)
      return;
    if (!root->left && !root->right)
      return;
    if (!root->right) {
      getRight(root->left, v);
    } else {
      getRight(root->right, v);
    }
    v.push_back(root->val);
  }

  void getLeaves(TreeNode *root, vector<int> &v) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      v.push_back(root->val);
    }
    getLeaves(root->left, v);
    getLeaves(root->right, v);
  }
};
