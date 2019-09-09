/*
 * @lc app=leetcode id=366 lang=cpp
 *
 * [366] Find Leaves of Binary Tree
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
  unordered_map<TreeNode *, int> d;
  vector<vector<int>> findLeaves(TreeNode *root) {
    depth(root);
    vector<vector<int>> res;
    for (auto &p : m) {
      res.push_back(p.second);
    }
    return res;
  }

  int depth(TreeNode *root) {
    if (!root)
      return 0;
    if (d.find(root) != d.end())
      return d[root];
    int res = max(depth(root->left), depth(root->right)) + 1;
    m[res].push_back(root->val);
    return d[root] = res;
  }
};
