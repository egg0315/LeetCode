/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.88%)
 * Likes:    6637
 * Dislikes: 388
 * Total Accepted:    1.1M
 * Total Submissions: 3.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int count[256] = {};
        int i = 0, repeat = 0, res = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            if (count[s[j]]++)
            {
                repeat++;
            }
            if (repeat == 0)
                res = max(res, j - i + 1);
            while (repeat)
            {
                if (count[s[i++]]-- == 2)
                    --repeat;
            }
        }
        return res;
    }
};
// @lc code=end
