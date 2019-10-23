/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.41%)
 * Likes:    2697
 * Dislikes: 341
 * Total Accepted:    463.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution
{
public:
    const vector<string> keypad = {"", "", "abc", "def",
                                   "ghi", "jkl", "mno",
                                   "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        string cur;
        dfs(digits, res, cur, 0);
        return res;
    }

    void dfs(string digits, vector<string> &res, string cur, int i)
    {
        if (i == digits.size())
        {
            if (cur != "")
                res.push_back(cur);
            return;
        }
        int x = digits[i] - '0';
        for (auto c : keypad[x])
        {
            dfs(digits, res, cur + c, i + 1);
        }
    }
};
// @lc code=end
