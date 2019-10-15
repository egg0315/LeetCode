/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 *
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (46.65%)
 * Likes:    445
 * Dislikes: 40
 * Total Accepted:    18.8K
 * Total Submissions: 40.1K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * Given an array A of integers, return the number of (contiguous, non-empty)
 * subarrays that have a sum divisible by K.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [4,5,0,-2,-3,1], K = 5
 * Output: 7
 * Explanation: There are 7 subarrays with a sum divisible by K = 5:
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  int subarraysDivByK(vector<int> &A, int K) {
    int counter[K] = {};
    int res = 0;
    int presum = 0;
    counter[0] = 1;
    for (auto i : A) {
      presum = (i + presum) % K;
      if (presum < 0)
        presum += K;
      res += counter[presum];
      counter[presum]++;
    }
    return res;
  }
};
// @lc code=end

