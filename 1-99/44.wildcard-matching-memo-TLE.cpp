/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (23.40%)
 * Likes:    1349
 * Dislikes: 81
 * Total Accepted:    200.5K
 * Total Submissions: 852.7K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, bool> memo;

    bool isMatch(string s, string p)
    {
        string key = s + "^" + p;
        if (memo.find(key) != memo.end())
            return memo[key];
        int pos = p.find("*");
        if (pos == string::npos)
            return memo[key] = isFuzzyMatch(s, p);
        if (pos > s.size())
            return memo[key] = false;
        string pLeft = p.substr(0, pos);
        string sLeft = s.substr(0, pos);
        if (!isFuzzyMatch(sLeft, pLeft))
            return memo[key] = false;
        string pRest = p.substr(pos + 1);
        for (int i = pos; i <= s.size(); ++i)
        {
            string sRest = s.substr(i);
            if (isMatch(sRest, pRest))
                return memo[key] = true;
        }
        return memo[key] = false;
    }

    bool isFuzzyMatch(string &s, string &p)
    {
        if (s.size() != p.size())
            return false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != p[i] && p[i] != '?')
                return false;
        }
        return true;
    }
};
// @lc code=end
