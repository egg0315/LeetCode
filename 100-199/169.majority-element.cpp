/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.21%)
 * Likes:    2035
 * Dislikes: 178
 * Total Accepted:    447.9K
 * Total Submissions: 822.2K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = nums[0];
        int score = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            score += nums[i] == major ? 1 : -1;
            if (score < 0)
            {
                score = 1;
                major = nums[i];
            }
        }
        return major;
    }
};
// @lc code=end
