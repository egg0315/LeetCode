/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 *
 * https://leetcode.com/problems/k-inverse-pairs-array/description/
 *
 * algorithms
 * Hard (29.74%)
 * Likes:    232
 * Dislikes: 73
 * Total Accepted:    8.6K
 * Total Submissions: 28.9K
 * Testcase Example:  '3\n0'
 *
 * Given two integers n and k, find how many different arrays consist of
 * numbers from 1 to n such that there are exactly k inverse pairs.
 * 
 * We define an inverse pair as following: For ith and jth element in the
 * array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's
 * not.
 * 
 * Since the answer may be very large, the answer should be modulo 10^9 + 7.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 0
 * Output: 1
 * Explanation: 
 * Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0
 * inverse pair.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, k = 1
 * Output: 2
 * Explanation: 
 * The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The integer n is in the range [1, 1000] and k is in the range [0, 1000].
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    const int mod = 1e9 + 7;
    int dp[1001] = {};
    int prefix[1002] = {};
    int kInversePairs(int n, int K)
    {
        // monotonic
        dp[0] = 1;
        // for number i
        for (int k = 0; k <= K; ++k)
            prefix[k] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int k = 1; k <= K; ++k)
            {
                dp[k] = k <= i - 1 ? prefix[k] : prefix[k] - prefix[k - i];
                dp[k] = dp[k] < 0 ? dp[k] + mod : dp[k];
                // will TLE
                // for(int j = 0; j <= min(k, i-1); ++j) {
                //     dp[i][k] = (dp[i][k] + dp[i-1][k-j])%mod;
                // }
            }
            // calculate prefix sum of current row
            int sum = 0;
            for (int k = 0; k <= K; ++k)
            {
                sum = (sum + dp[k]) % mod;
                prefix[k] = sum;
            }
        }
        return dp[K];
    }
};
// @lc code=end
