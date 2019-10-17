/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.77%)
 * Likes:    832
 * Dislikes: 360
 * Total Accepted:    193K
 * Total Submissions: 588.6K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return false;
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;
            if (l < mid && nums[l] == nums[mid])
            {
                ++l;
            }
            // left is sorted
            else if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && nums[mid] > target)
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            // right is sorted
            else
            {
                if (nums[mid] < target && nums[r] >= target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
