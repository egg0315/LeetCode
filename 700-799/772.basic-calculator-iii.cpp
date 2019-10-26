/*
 * @lc app=leetcode id=772 lang=cpp
 *
 * [772] Basic Calculator III
 *
 * https://leetcode.com/problems/basic-calculator-iii/description/
 *
 * algorithms
 * Hard (41.33%)
 * Likes:    302
 * Dislikes: 97
 * Total Accepted:    23.3K
 * Total Submissions: 56.5K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators , open ( and closing parentheses ) and empty spaces  . The integer
 * division should truncate toward zero.
 * 
 * You may assume that the given expression is always valid. All intermediate
 * results will be in the range of [-2147483648, 2147483647].
 * 
 * Some examples:
 * 
 * 
 * "1 + 1" = 2
 * " 6-4 / 2 " = 4
 * "2*(5+5*2)/3+(6/2+8)" = 21
 * "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 * 
 * 
 * 
 * 
 * Note: Do not use the eval built-in library function.
 * 
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        int i = 0;
        return parseExpr(s, i);
    }

    int parseExpr(string &s, int &i)
    {
        vector<long> nums;
        char op = '+';
        for (; i < s.size() && op != ')'; ++i)
        {
            if (s[i] == ' ')
                continue;
            long n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
            switch (op)
            {
            case '+':
                nums.push_back(n);
                break;
            case '-':
                nums.push_back(-n);
                break;
            case '*':
                nums.back() *= n;
                break;
            case '/':
                nums.back() /= n;
                break;
            }
            op = s[i];
        }
        int res = 0;
        for (auto i : nums)
            res += i;
        return res;
    }

    long parseNum(string &s, int &i)
    {
        long num = 0;
        while (i < s.size() && isdigit(s[i]))
        {
            num *= 10;
            num += s[i] - '0';
            ++i;
        }
        return num;
    }
};
// @lc code=end
