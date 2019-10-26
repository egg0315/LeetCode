/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (34.40%)
 * Likes:    962
 * Dislikes: 105
 * Total Accepted:    127.3K
 * Total Submissions: 370K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * Example 1:
 * 
 * 
 * Input: "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 2-1 + 2 "
 * Output: 3
 * 
 * Example 3:
 * 
 * 
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        s += '+';
        string e;
        for (auto c : s)
        {
            if (c != ' ')
                e += c;
        }
        long res = 0, term = 0, sign = 1;
        stack<long> st;
        stack<long> ops;
        for (auto &c : e)
        {
            if (c >= '0' && c <= '9')
            {
                term = term * 10 + c - '0';
            }
            else if (c == '+' || c == '-')
            {
                res += term * sign;
                sign = c == '+' ? 1 : -1;
                term = 0;
            }
            else if (c == '(')
            {
                st.push(res);
                ops.push(sign);
                sign = 1;
                res = 0;
                term = 0;
            }
            else if (c == ')')
            {
                res += term * sign;
                term = 0;
                sign = 1;
                res = st.top() + res * ops.top();
                st.pop();
                ops.pop();
            }
        }
        return res;
    }
};
// @lc code=end
