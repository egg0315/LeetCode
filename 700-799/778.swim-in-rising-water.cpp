/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 *
 * https://leetcode.com/problems/swim-in-rising-water/description/
 *
 * algorithms
 * Hard (48.86%)
 * Likes:    360
 * Dislikes: 33
 * Total Accepted:    15K
 * Total Submissions: 30.6K
 * Testcase Example:  '[[0,2],[1,3]]'
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that
 * point (i,j).
 * 
 * Now rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and
 * only if the elevation of both squares individually are at most t. You can
 * swim infinite distance in zero time. Of course, you must stay within the
 * boundaries of the grid during your swim.
 * 
 * You start at the top left square (0, 0). What is the least time until you
 * can reach the bottom right square (N-1, N-1)?
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have
 * a higher elevation than t = 0.
 * 
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 * ⁠0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 * 
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
 * 
 * 
 */
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int low = max(grid[0][0], grid[n - 1][n - 1]), high = n * n - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (valid(mid, grid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    bool valid(int h, vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n));
        return dfs(0, 0, h, grid, visited);
    }

    bool dfs(int i, int j, int h, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > h)
            return false;
        if (i == n - 1 && j == n - 1)
            return true;
        visited[i][j] = true;
        if (dfs(i + 1, j, h, grid, visited) ||
            dfs(i - 1, j, h, grid, visited) ||
            dfs(i, j + 1, h, grid, visited) ||
            dfs(i, j - 1, h, grid, visited))
        {
            return true;
        }
        return false;
    }
};
