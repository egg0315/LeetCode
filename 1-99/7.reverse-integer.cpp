/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.50%)
 * Likes:    2512
 * Dislikes: 3925
 * Total Accepted:    834.4K
 * Total Submissions: 3.3M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long long num = abs((long)x);
        long long rev = 0;
        while (num)
        {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        if (x < 0)
            rev = -rev;
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;
        return rev;
    }
};
// @lc code=end
