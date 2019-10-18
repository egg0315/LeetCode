/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    1974
 * Dislikes: 144
 * Total Accepted:    343.6K
 * Total Submissions: 692.5K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */

// @lc code=start
class Solution
{
    class Solution
    {
    public:
        int uniquePaths(int m, int n)
        {
            vector<vector<int>> dp(2, vector<int>(n, 1));

            for (int i = 1; i < m; ++i)
                for (int j = 1; j < n; ++j)
                    dp[i & 1][j] = dp[1 - i & 1][j] + dp[i & 1][j - 1];

            return dp[(m - 1) & 1][n - 1];
        }
    };
    // @lc code=end
