/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.70%)
 * Likes:    3175
 * Dislikes: 592
 * Total Accepted:    350.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
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
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    // key to val
    unordered_map<string, bool> memo;
    bool isMatch(string s, string p)
    {
        int pos = p.find("*");
        string key = s + "%" + p;
        if (memo.find(key) != memo.end())
            return memo[key];
        if (pos == string::npos)
            return memo[key] = isFuzzyMatch(s, p);
        if (pos - 1 > s.size())
            return false;
        string sLeft = s.substr(0, pos - 1);
        string pLeft = p.substr(0, pos - 1);
        // sleft and pLeft need to match
        if (!isFuzzyMatch(sLeft, pLeft))
            return memo[key] = false;
        string pRest = p.substr(pos + 1);
        // * match no char in s
        if (isMatch(s.substr(pos - 1), pRest))
            return memo[key] = true;
        // match 1 or more char
        int i = pos - 1;
        while (i < s.size() && (s[i] == p[pos - 1] || p[pos - 1] == '.'))
        {
            if (isMatch(s.substr(i + 1), pRest))
                return memo[key] = true;
            ++i;
        }
        return memo[key] = false;
    }

    bool isFuzzyMatch(string &s, string &p)
    {
        if (s.size() != p.size())
            return false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != p[i] && p[i] != '.')
                return false;
        }
        return true;
    }
};
// @lc code=end
