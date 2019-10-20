/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (35.65%)
 * Likes:    1420
 * Dislikes: 83
 * Total Accepted:    201.9K
 * Total Submissions: 564.1K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size(), res = n + 1;
        int i = 0;
        for (int j = 0; j < n; ++j)
        {
            s -= nums[j];
            while (s <= 0)
            {
                res = min(res, j - i + 1);
                s += nums[i++];
            }
        }
        return res == n + 1 ? 0 : res;
    }
};
// @lc code=end
