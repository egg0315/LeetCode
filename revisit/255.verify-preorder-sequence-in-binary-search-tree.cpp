/*
 * @lc app=leetcode id=255 lang=cpp
 *
 * [255] Verify Preorder Sequence in Binary Search Tree
 *
 * https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/
 *
 * algorithms
 * Medium (44.27%)
 * Likes:    417
 * Dislikes: 44
 * Total Accepted:    39.6K
 * Total Submissions: 89.3K
 * Testcase Example:  '[5,2,6,1,3]'
 *
 * Given an array of numbers, verify whether it is the correct preorder
 * traversal sequence of a binary search tree.
 *
 * You may assume each number in the sequence is unique.
 *
 * Consider the following binary search tree: 
 *
 *
 * ⁠    5
 * ⁠   / \
 * ⁠  2   6
 * ⁠ / \
 * ⁠1   3
 *
 * Example 1:
 *
 *
 * Input: [5,2,6,1,3]
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: [5,2,1,3,6]
 * Output: true
 *
 * Follow up:
 * Could you do it using only constant space complexity?
 *
 */
class Solution {
public:
  bool verifyPreorder(vector<int> &v) {
    // hold left tree
    stack<int> st;
    int low = INT_MIN;
    for (auto i : v) {
      if (i < low)
        return false;
      while (st.size() && st.top() < i) {
        low = st.top();
        st.pop();
      }
      st.push(i);
    }
    return true;
  }
};
