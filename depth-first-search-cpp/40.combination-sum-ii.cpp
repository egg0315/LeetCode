/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(begin(nums), end(nums));
    dfs(nums, 0, target, path, res);
    return res;
  }

  void dfs(vector<int> &nums, int start, int target, vector<int> &path,
           vector<vector<int>> &res) {
    if (target == 0) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1])
        continue;
      if (nums[i] > target)
        break;
      path.push_back(nums[i]);
      dfs(nums, i + 1, target - nums[i], path, res);
      path.pop_back();
    }
  }
};
