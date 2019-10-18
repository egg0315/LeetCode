/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.16%)
 * Likes:    815
 * Dislikes: 3932
 * Total Accepted:    222.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // over flow case
        // INT_MIN / -1
        if (divisor == 1)
            return dividend;
        if (divisor == -1 && dividend == INT_MIN)
            return INT_MAX;
        if (dividend == 0)
            return 0;
        int res = 0;
        long remain = abs((long)dividend);
        long div = abs((long)divisor);
        int base = 1;
        while (remain >= div)
        {
            int i = 0;
            while (div << (i + 1) <= remain)
            {
                ++i;
            }
            res += (1 << i);
            remain -= div << i;
        }
        return (dividend < 0) ^ (divisor < 0) ? -res : res;
    }
};
// @lc code=end
