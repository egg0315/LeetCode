/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */
class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    int n = nums.size(), i = 0;
    while (i < n) {
      while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
      ++i;
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1)
        res.push_back(nums[i]);
    }
    return res;
  }
};
