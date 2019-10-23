/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.63%)
 * Likes:    3460
 * Dislikes: 206
 * Total Accepted:    409.3K
 * Total Submissions: 710.1K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string cur;
        dfs(res, cur, 0, 0, n);
        return res;
    }

    void dfs(vector<string> &res, string cur, int left, int right, int n)
    {
        if (left == n && right == n)
        {
            res.push_back(cur);
        }
        if (left < right || left > n || right > n)
            return;

        dfs(res, cur + "(", left + 1, right, n);
        dfs(res, cur + ")", left, right + 1, n);
    }
};
// @lc code=end
