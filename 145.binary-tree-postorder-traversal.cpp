/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (50.75%)
 * Likes:    1167
 * Dislikes: 63
 * Total Accepted:    300.1K
 * Total Submissions: 590.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [3,2,1]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* last = nullptr;
        while(root || st.size()) {
            if(root) {
                st.push(root);
                root = root->left;
            }
            else {
                auto node = st.top();
                if(node->right && last != node->right) {
                    root = node->right;
                }
                else {
                    res.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }
        }
        return res;
        
    }
};
// @lc code=end

