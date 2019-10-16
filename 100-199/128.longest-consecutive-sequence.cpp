/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int res = 0;
    for (auto x : nums) {
      if (s.find(x) == s.end())
        continue;
      int l = x, r = x + 1;
      while (s.find(l) != s.end()) {
        s.erase(l--);
      }
      while (s.find(r) != s.end()) {
        s.erase(r++);
      }
      res = max(res, r - l - 1);
    }
    return res;
  }
};
