/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.24%)
 * Likes:    923
 * Dislikes: 268
 * Total Accepted:    235.8K
 * Total Submissions: 613.8K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() - t.size())
            return false;
        int m1[256] = {};
        int m2[256] = {};
        for (int i = 0; i < s.size(); ++i)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = m2[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end
