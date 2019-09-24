/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (48.54%)
 * Likes:    668
 * Dislikes: 185
 * Total Accepted:    87.5K
 * Total Submissions: 180.2K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
class Solution
{
public:
    // int integerBreak(int n) {
    //     if(n == 2)
    //         return 1;
    //     if(n == 3)
    //         return 2;
    //     int dp[n+1] = {};
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     dp[3] = 3;
    //     for(int i = 4; i <= n; ++i) {
    //         for(int j = 1; j < i; ++j) {
    //             dp[i] = max(dp[i], dp[j] * dp[i-j]);
    //             dp[i] = max(dp[i], j * dp[i-j]);
    //         }
    //     }
    //     return dp[n];
    // }
    // math
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int product = 1;
        while (n > 4)
        {
            product *= 3;
            n -= 3;
        }
        product *= n;
        return product;
    }
};
