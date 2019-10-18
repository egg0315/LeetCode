/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.86%)
 * Likes:    1330
 * Dislikes: 452
 * Total Accepted:    276.3K
 * Total Submissions: 921.7K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> seive(n + 1, true);
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (seive[i])
            {
                ++count;
                for (int k = 2; k * i <= n; ++k)
                {
                    seive[k * i] = false;
                }
            }
        }
        return count;
    }
};
// @lc code=end
