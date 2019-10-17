/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.28%)
 * Likes:    3459
 * Dislikes: 169
 * Total Accepted:    724.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2)
            return false;
        string st;
        for (auto &c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st += c;
            else if (st.empty())
                return false;
            else if (c == ')' && st.back() == '(')
                st.pop_back();
            else if (c == ']' && st.back() == '[')
                st.pop_back();
            else if (c == '}' && st.back() == '{')
                st.pop_back();
            else
                return false;
        }
        return st.empty();
    }
};
// @lc code=end
