/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (52.35%)
 * Likes:    653
 * Dislikes: 124
 * Total Accepted:    243.4K
 * Total Submissions: 463.4K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(string s)
    {
        int res = 0;
        int N = 26;
        long base = 1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            res += base * (s[i] - 'A' + 1);
            base *= N;
        }
        return res;
    }
};
// @lc code=end
