/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (42.80%)
 * Likes:    1167
 * Dislikes: 48
 * Total Accepted:    185.4K
 * Total Submissions: 430.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

    void dfs(string &s, int start, vector<string> &path, vector<vector<string>> &res)
    {
        int n = s.size();
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = start + 1; i <= n; ++i)
        {
            string temp = s.substr(start, i - start);
            if (isPalindrome(temp))
            {
                path.push_back(temp);
                dfs(s, i, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
// @lc code=end
