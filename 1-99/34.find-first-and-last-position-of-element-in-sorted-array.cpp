/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.41%)
 * Likes:    2123
 * Dislikes: 99
 * Total Accepted:    366.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start
class Solution
{
public:
    //  every time use *it check if it == end()\
    // write a manual binary search
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto bounds = equal_range(nums.begin(), nums.end(), target);
        if (bounds.first == bounds.second)
            return {-1, -1};
        return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
    }
};
// @lc code=end
