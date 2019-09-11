/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
  vector<int> largestValues(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
      int len = q.size();
      TreeNode *mx = NULL;
      for (int i = 0; i < len; ++i) {
        auto cur = q.front();
        q.pop();
        if (mx == NULL || cur->val > mx->val) {
          mx = cur;
        }
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
      res.push_back(mx->val);
    }
    return res;
  }
};
