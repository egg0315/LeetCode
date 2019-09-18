/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    do {
      res.push_back(nums);
    } while (next_permutation(begin(nums), end(nums)));
    return res;
  }
};
