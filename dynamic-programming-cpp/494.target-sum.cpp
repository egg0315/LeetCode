/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    int sum = accumulate(begin(nums), end(nums), 0);
    if (sum < S || (sum + S) % 2)
      return 0;
    sum += S;
    return subsetSum(nums, sum / 2);
  }

  int subsetSum(vector<int> &nums, int S) {
    int dp[S + 1] = {};
    dp[0] = 1;
    for (auto n : nums) {
      for (int i = S; i >= n; --i)
        dp[i] += dp[i - n];
    }
    return dp[S];
  }
};
