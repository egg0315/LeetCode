/*
 * @lc app=leetcode id=250 lang=cpp
 *
 * [250] Count Univalue Subtrees
 *
 * https://leetcode.com/problems/count-univalue-subtrees/description/
 *
 * algorithms
 * Medium (50.02%)
 * Likes:    333
 * Dislikes: 75
 * Total Accepted:    45.7K
 * Total Submissions: 91.2K
 * Testcase Example:  '[5,1,5,5,5,null,5]'
 *
 * Given a binary tree, count the number of uni-value subtrees.
 *
 * A Uni-value subtree means all nodes of the subtree have the same value.
 *
 * Example :
 *
 *
 * Input:  root = [5,1,5,5,5,null,5]
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           1   5
 * ⁠          / \   \
 * ⁠         5   5   5
 *
 * Output: 4
 *
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
  unordered_map<TreeNode *, bool> memo;
  int count = 0;
  int countUnivalSubtrees(TreeNode *root) {
    allSame(root);
    return count;
  }

  bool allSame(TreeNode *root) {
    if (!root)
      return true;
    bool left = allSame(root->left);
    bool right = allSame(root->right);
    if (left && right) {
      if ((!root->left || root->left->val == root->val) &&
          (!root->right || root->right->val == root->val)) {
        ++count;
        return true;
      }
    }
    return false;
  }
};
