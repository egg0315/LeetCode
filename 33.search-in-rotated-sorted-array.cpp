/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.27%)
 * Likes:    3098
 * Dislikes: 368
 * Total Accepted:    501.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
class Solution
{
public:
    // Using STL strictly
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        auto pivot = min_element(begin(nums), end(nums));
        rotate(begin(nums), pivot, end(nums));
        auto it = lower_bound(begin(nums), end(nums), target);
        return (it == end(nums) || *it != target) ? -1 : (it - begin(nums) + (pivot - begin(nums))) % nums.size();
    }
};
// @lc code=end
