/*
 * @lc app=leetcode id=333 lang=cpp
 *
 * [333] Largest BST Subtree
 *
 * https://leetcode.com/problems/largest-bst-subtree/description/
 *
 * algorithms
 * Medium (33.86%)
 * Likes:    415
 * Dislikes: 42
 * Total Accepted:    35.2K
 * Total Submissions: 103.7K
 * Testcase Example:  '[10,5,15,1,8,null,7]'
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree
 * (BST), where largest means subtree with largest number of nodes in it.
 *
 * Note:
 * A subtree must include all of its descendants.
 *
 * Example:
 *
 *
 * Input: [10,5,15,1,8,null,7]
 *
 * ⁠  10
 * ⁠  / \
 * ⁠ 5  15
 * ⁠/ \   \
 * 1   8   7
 *
 * Output: 3
 * Explanation: The Largest BST Subtree in this case is the highlighted one.
 * ⁠            The return value is the subtree's size, which is 3.
 *
 *
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
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
class Solution {
public:
  int res = 0;
  int largestBSTSubtree(TreeNode *root) {
    dfs(root);
    return res;
  }
  // size , min, max
  vector<int> dfs(TreeNode *root) {
    if (!root)
      return {0, INT_MAX, INT_MIN};
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    if (left[0] == -1 || right[0] == -1 || root->val <= left[2] ||
        root->val >= right[1]) {
      return {-1, 0, 0};
    }
    int sz = left[0] + right[0] + 1;
    res = max(res, sz);
    return {sz, min(left[1], root->val), max(right[2], root->val)};
  }
};
