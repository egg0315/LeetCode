/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
  unordered_map<TreeNode *, vector<TreeNode *>> mp;
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    if (K == 0)
      return {target->val};
    // convert tree to adjcent list map;
    traverse(root);
    // start from target, all node distance K
    queue<TreeNode *> q;
    q.push(target);
    int step = 0;
    unordered_set<TreeNode *> visited;
    visited.insert(target);

    while (q.size()) {
      int sz = q.size();
      for (int k = 0; k < sz; ++k) {
        auto cur = q.front();
        q.pop();
        for (auto next : mp[cur]) {
          if (visited.count(next) == 0) {
            q.push(next);
            visited.insert(next);
          }
        }
      }
      ++step;
      if (step == K)
        break;
    }
    vector<int> res;

    while (q.size()) {
      res.push_back(q.front()->val);
      q.pop();
    }
    return res;
  }
  // preorder
  void traverse(TreeNode *root) {
    if (!root)
      return;
    if (root->left) {
      mp[root].push_back(root->left);
      mp[root->left].push_back(root);
      traverse(root->left);
    }
    if (root->right) {
      mp[root].push_back(root->right);
      mp[root->right].push_back(root);
      traverse(root->right);
    }
  }
};
