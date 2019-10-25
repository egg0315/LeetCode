/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (34.85%)
 * Likes:    903
 * Dislikes: 161
 * Total Accepted:    134.3K
 * Total Submissions: 385.3K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
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
        s = '+' + s + '+';
        stringstream in(s);
        int res = 0, term = 0;
        char op;
        while (in >> op)
        {
            if (op == '+' || op == '-')
            {
                res += term;
                in >> term;
                term = op == '+' ? term : -term;
            }
            else
            {
                int tmp;
                in >> tmp;
                term = op == '*' ? term * tmp : term / tmp;
            }
        }
        return res;
    }
};
// @lc code=end
