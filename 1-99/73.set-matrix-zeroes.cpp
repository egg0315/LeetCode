/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (40.90%)
 * Likes:    1333
 * Dislikes: 231
 * Total Accepted:    243.8K
 * Total Submissions: 592.9K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        if (m == 0)
            return;
        bool firstRowZero = any_of(begin(matrix[0]), end(matrix[0]), [](int x) { return x == 0; });
        bool firstColumnZero = false;
        for (int i = 0; i < m; ++i)
            firstColumnZero |= matrix[i][0] == 0;
        // mark zeros
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (!matrix[i][j])
                {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        // set zeros
        for (int i = 1; i < m; ++i)
        {
            if (!matrix[i][0])
            {
                for (int j = 1; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; ++j)
        {
            if (!matrix[0][j])
            {
                for (int i = 1; i < m; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        // set first Row and column
        if (firstRowZero)
        {
            matrix[0].assign(n, 0);
        }
        if (firstColumnZero)
        {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
    }
};
// @lc code=end
