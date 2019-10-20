/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (36.89%)
 * Likes:    440
 * Dislikes: 431
 * Total Accepted:    143.2K
 * Total Submissions: 385.8K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (j == nums.size() - 1 || nums[j + 1] > nums[j] + 1)
            {
                if (i != j)
                    res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                else
                    res.push_back(to_string(nums[i]));
                i = j + 1;
            }
        }
        return res;
    }
};
// @lc code=end
