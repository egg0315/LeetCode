/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    unordered_map<int, int> dp;
    dp[0] = 1;
    for (auto &i : nums) {
      unordered_map<int, int> next;
      for (auto &p : dp) {
        next[p.first + i] += p.second;
        next[p.first - i] += p.second;
      }
      dp = next;
    }
    return dp[S];
  }
};
