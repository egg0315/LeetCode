/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 * Note : use nested dfs instead of four parallel dfs
 */
class Solution {
public:
  bool makesquare(vector<int> &nums) {
    int total = accumulate(begin(nums), end(nums), 0);
    if (total == 0)
      return false;
    if (total % 4)
      return false;
    total /= 4;
    vector<bool> used(nums.size(), false);
    return dfs(nums, used, 0, total, total, 0);
  }

  bool dfs(vector<int> &nums, vector<bool> &used, int start, int remain,
           int target, int edge) {
    if (edge == 4)
      return true;
    if (remain == 0) {
      return dfs(nums, used, 0, target, target, edge + 1);
    }
    for (int i = start; i < nums.size(); ++i) {
      if (!used[i] && remain >= nums[i]) {
        used[i] = true;
        if (dfs(nums, used, i + 1, remain - nums[i], target, edge))
          return true;
        used[i] = false;
      }
    }
    return false;
  }
};
