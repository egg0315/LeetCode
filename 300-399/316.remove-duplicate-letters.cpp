/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (33.65%)
 * Likes:    922
 * Dislikes: 87
 * Total Accepted:    64.6K
 * Total Submissions: 192K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appears once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 * 
 * Example 1:
 * 
 * 
 * Input: "bcabc"
 * Output: "abc"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbacdcbc"
 * Output: "acdb"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> count(26, 0);
        for (auto &c : s)
            count[c - 'a']++;
        vector<bool> used(26, false);
        string res;
        for (auto &c : s)
        {
            count[c - 'a']--;
            if (used[c - 'a'])
                continue;
            while (!res.empty() && c < res.back() && count[res.back() - 'a'])
            {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            if (!used[c - 'a'])
            {
                res += c;
                used[c - 'a'] = true;
            }
        }
        return res;
    }
};
// @lc code=end
