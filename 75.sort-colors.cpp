/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int count[3] = {};
    for (auto &i : nums) {
      ++count[i];
    }

    int i = 0;
    for (int k = 0; k < 3; ++k) {
      while (count[k]-- > 0) {
        nums[i++] = k;
      }
    }
  }
};
