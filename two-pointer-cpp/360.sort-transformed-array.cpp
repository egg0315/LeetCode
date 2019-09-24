/*
 * @lc app=leetcode id=360 lang=cpp
 *
 * [360] Sort Transformed Array
 *
 * https://leetcode.com/problems/sort-transformed-array/description/
 *
 * algorithms
 * Medium (47.29%)
 * Likes:    242
 * Dislikes: 71
 * Total Accepted:    29.2K
 * Total Submissions: 61.6K
 * Testcase Example:  '[-4,-2,2,4]\n1\n3\n5'
 *
 * Given a sorted array of integers nums and integer values a, b and c. Apply a
 * quadratic function of the form f(x) = ax^2 + bx + c to each element x in the
 * array.
 *
 * The returned array must be in sorted order.
 *
 * Expected time complexity: O(n)
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
 * Output: [3,9,15,33]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
 * Output: [-23,-5,1,7]
 *
 *
 *
 */
class Solution {
public:
  int aa, bb, cc;
  vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
    aa = a;
    bb = b;
    cc = c;
    vector<int> res(nums.size());
    int l = 0, r = nums.size() - 1;
    int index = a >= 0 ? nums.size() - 1 : 0;

    while (l <= r) {
      if (a >= 0) {
        res[index--] =
            quad(nums[l]) < quad(nums[r]) ? quad(nums[r--]) : quad(nums[l++]);
      } else {
        res[index++] =
            quad(nums[l]) < quad(nums[r]) ? quad(nums[l++]) : quad(nums[r--]);
      }
    }
    return res;
  }

  int quad(int x) { return aa * x * x + bb * x + cc; }
};
