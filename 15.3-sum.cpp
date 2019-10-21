/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.80%)
 * Likes:    4714
 * Dislikes: 558
 * Total Accepted:    674.9K
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        sort(begin(nums), end(nums));
        int i = 0, j = -1, k = -1;
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                int t = nums[j] + nums[k]; // No.1
                if (t > target)
                    --k;
                else if (t < target)
                    ++j;
                else
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    res.push_back(triplet);
                    while (j < k && nums[j] == nums[j + 1])
                        ++j;
                    while (j < k && nums[k] == nums[k - 1])
                        --k;
                    ++j;
                    --k;
                }
            }
        }
        return res;
    }
};
// @lc code=end
