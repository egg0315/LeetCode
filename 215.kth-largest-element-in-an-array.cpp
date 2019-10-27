/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (50.46%)
 * Likes:    2525
 * Dislikes: 196
 * Total Accepted:    458K
 * Total Submissions: 907.3K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        k = nums.size() - k;
        int left = 0, right = nums.size() - 1;
        int index;
        while (true)
        {
            index = partition(nums, left, right);
            if (index == k)
            {
                break;
            }
            else if (index > k)
            {
                right = index - 1;
            }
            else
            {
                left = index + 1;
            }
        }
        return nums[index];
    }

    int partition(vector<int> &nums, int lo, int hi)
    {
        int pivot = nums[lo], l = lo, r = hi;
        while (l < r)
        {
            while (l <= r && nums[l] <= pivot)
            {
                ++l;
            }
            while (l <= r && nums[r] >= pivot)
            {
                --r;
            }
            if (l < r)
            {
                swap(nums[l++], nums[r--]);
            }
        }
        swap(nums[lo], nums[r]);
        return r;
    }
};
// @lc code=end
