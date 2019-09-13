/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> v1, v2;
    travel(root1, v1);
    travel(root2, v2);
    return v1 == v2;
  }

  void travel(TreeNode *root, vector<int> &v) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      v.push_back(root->val);
      return;
    }
    travel(root->left, v);
    travel(root->right, v);
  }
};
