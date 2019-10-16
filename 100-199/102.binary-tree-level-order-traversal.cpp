/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 * tag : tree, bfs
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
      return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> level;
      for (int i = q.size(); i > 0; --i) {
        auto cur = q.front();
        q.pop();
        level.push_back(cur->val);
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      res.push_back(level);
    }
    return res;
  }
};
