/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 * tag : binary search
 */
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> tail; // tail will be sorted
    for (auto x : nums) {
      auto it = lower_bound(tail.begin(), tail.end(), x);
      if (it == tail.end()) {
        tail.push_back(x);
      } else {
        *it = min(*it, x);
      }
    }
    return tail.size();
  }
};
