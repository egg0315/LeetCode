/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
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
  map<int, vector<int>> m;
  vector<vector<int>> verticalOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
      return res;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        int x = q.front().second;
        auto cur = q.front().first;
        q.pop();
        m[x].push_back(cur->val);
        if (cur->left)
          q.push({cur->left, x - 1});
        if (cur->right) {
          q.push({cur->right, x + 1});
        }
      }
    }
    for (auto &[x, v] : m) {
      res.push_back(v);
    }
    return res;
  }
};
