/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (28.59%)
 * Likes:    993
 * Dislikes: 2414
 * Total Accepted:    368.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int ex)
    {
        bool neg = false;
        long n = ex;
        if (n < 0)
        {
            neg = true;
            n = -n;
        }
        double res = 1.0;
        int exp = 1;
        double base = x;
        while (n > 0)
        {
            while (exp < n / 2)
            {
                exp *= 2;
                base *= base;
            }
            while (exp > n)
            {
                exp /= 2;
                base = (exp % 2 && x < 0) ? -sqrt(base) : sqrt(base);
            }
            res *= base;
            n -= exp;
        }
        return neg ? 1 / res : res;
    }
};
// @lc code=end
