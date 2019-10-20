/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.15%)
 * Likes:    1674
 * Dislikes: 1507
 * Total Accepted:    564K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string prefix = "";
        int j = 0;
        while (j < strs[0].size())
        {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i].size() <= j || strs[i][j] != c)
                {
                    return prefix;
                }
            }
            prefix += c;
            j++;
        }
        return prefix;
    }
};
// @lc code=end
