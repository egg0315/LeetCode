/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 *
 * https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
 *
 * algorithms
 * Hard (39.16%)
 * Likes:    119
 * Dislikes: 48
 * Total Accepted:    6.2K
 * Total Submissions: 15.8K
 * Testcase Example:  '0'
 *
 * Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 1 * 2 *
 * 3 * ... * x, and by convention, 0! = 1.)
 * 
 * For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) =
 * 2 because 11! = 39916800 has 2 zeroes at the end. Given K, find how many
 * non-negative integers x have the property that f(x) = K.
 * 
 * 
 * Example 1:
 * Input: K = 0
 * Output: 5
 * Explanation: 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.
 * 
 * Example 2:
 * Input: K = 5
 * Output: 0
 * Explanation: There is no x such that x! ends in K = 5 zeroes.
 * 
 * 
 * Note:
 * 
 * 
 * K will be an integer in the range [0, 10^9].
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int preimageSizeFZF(int K)
    {
        for (long l = 0, r = 1e12; l < r;)
        {
            long m = l + (r - l) / 2;
            long k = numOfTailingZeros(m);
            if (k == K)
            {
                return 5;
            }
            else if (k < K)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return 0;
    }

    long numOfTailingZeros(long num)
    {
        long res = 0;
        for (long base = 5; base <= num; base *= 5)
        {
            res += num / base;
        }
        return res;
    }
};
// @lc code=end
