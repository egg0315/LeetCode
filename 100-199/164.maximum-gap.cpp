/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (33.40%)
 * Likes:    605
 * Dislikes: 141
 * Total Accepted:    76.6K
 * Total Submissions: 228.3K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 * 
 * Note:
 * 
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        int maxx = *max_element(begin(nums), end(nums));
        int minn = *min_element(begin(nums), end(nums));
        if (maxx == minn)
            return 0;
        // n-2 element except maxx and minn
        double interval = (maxx - minn) / (double)(n - 1);
        // n-1 bucket, atlease one is empty

        int gap = 0;
        vector<int> maxNum(n, INT_MIN);
        vector<int> minNum(n, INT_MAX);
        for (auto i : nums)
        {
            int index = (i - minn) / interval;
            maxNum[index] = max(maxNum[index], i);
            minNum[index] = min(minNum[index], i);
        }
        int prev = maxNum[0];
        for (int i = 1; i < n; ++i)
        {
            if (maxNum[i] == INT_MIN)
                continue;
            gap = max(gap, minNum[i] - prev);
            prev = maxNum[i];
        }
        return gap;
    }
};
// @lc code=end
