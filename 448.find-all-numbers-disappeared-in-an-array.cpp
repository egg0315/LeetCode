/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
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
        res.push_back(i + 1);
    }
    return res;
  }
};
