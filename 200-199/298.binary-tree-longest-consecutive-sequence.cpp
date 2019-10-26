/*
 * @lc app=leetcode id=298 lang=cpp
 *
 * [298] Binary Tree Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (45.10%)
 * Likes:    371
 * Dislikes: 92
 * Total Accepted:    68.2K
 * Total Submissions: 151.3K
 * Testcase Example:  '[1,null,3,2,4,null,null,null,5]'
 *
 * Given a binary tree, find the length of the longest consecutive sequence
 * path.
 * 
 * The path refers to any sequence of nodes from some starting node to any node
 * in the tree along the parent-child connections. The longest consecutive path
 * need to be from parent to child (cannot be the reverse).
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   / \
 * ⁠  2   4
 * ⁠       \
 * ⁠        5
 * 
 * Output: 3
 * 
 * Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 
 * ⁠  2
 * ⁠   \
 * ⁠    3
 * ⁠   / 
 * ⁠  2    
 * ⁠ / 
 * ⁠1
 * 
 * Output: 2 
 * 
 * Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return
 * 2.
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int res = 0;
    int longestConsecutive(TreeNode *root)
    {
        dfs(root, 1);
        return res;
    }

    void dfs(TreeNode *root, int len)
    {
        if (!root)
            return;
        res = max(res, len);
        if (root->left && root->left->val == root->val + 1)
        {
            dfs(root->left, len + 1);
        }
        else
        {
            dfs(root->left, 1);
        }
        if (root->right && root->right->val == root->val + 1)
        {
            dfs(root->right, len + 1);
        }
        else
        {
            dfs(root->right, 1);
        }
    }
};
// @lc code=end
