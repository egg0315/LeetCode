/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      if (nums[l] < nums[r]) {
        return nums[l];
      }
      int mid = (l + r) / 2;
      if (nums[mid] >= nums[l]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return nums[l];
  }
};
