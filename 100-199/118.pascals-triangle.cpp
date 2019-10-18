/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.01%)
 * Likes:    879
 * Dislikes: 84
 * Total Accepted:    296K
 * Total Submissions: 612.4K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> res;
        if (n == 0)
            return res;
        res.push_back({1});
        if (n == 1)
            return res;
        for (int i = 2; i <= n; ++i)
        {
            // ith row
            vector<int> row(i, 1);
            for (int k = 1; k + 1 < i; ++k)
            {
                row[k] = res.back()[k - 1] + res.back()[k];
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end
