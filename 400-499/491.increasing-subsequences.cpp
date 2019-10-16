/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 * Note : using hashset inside each level to record used numbers to avoid
 * duplicates
 */
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, path, res);
    return res;
  }

  void dfs(vector<int> &nums, int start, vector<int> &path,
           vector<vector<int>> &res) {
    if (path.size() > 1) {
      res.push_back(path);
    }
    unordered_set<int> used;
    for (int i = start; i < nums.size(); ++i) {
      if ((path.empty() || nums[i] >= path.back()) &&
          used.find(nums[i]) == used.end()) {
        path.push_back(nums[i]);
        dfs(nums, i + 1, path, res);
        path.pop_back();
        used.insert(nums[i]);
      }
    }
  }
};
