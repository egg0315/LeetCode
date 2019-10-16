/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Cut Off Trees for Golf Event
 *
 * https://leetcode.com/problems/cut-off-trees-for-golf-event/description/
 *
 * algorithms
 * Hard (32.12%)
 * Likes:    354
 * Dislikes: 205
 * Total Accepted:    21K
 * Total Submissions: 64.5K
 * Testcase Example:  '[[1,2,3],[0,0,4],[7,6,5]]'
 *
 * You are asked to cut off trees in a forest for a golf event. The forest is
 * represented as a non-negative 2D map, in this map:
 * 
 * 
 * 0 represents the obstacle can't be reached.
 * 1 represents the ground can be walked through.
 * The place with number bigger than 1 represents a tree can be walked through,
 * and this positive number represents the tree's height.
 * 
 * 
 * 
 * 
 * You are asked to cut off all the trees in this forest in the order of tree's
 * height - always cut off the tree with lowest height first. And after
 * cutting, the original place has the tree will become a grass (value 1).
 * 
 * You will start from the point (0, 0) and you should output the minimum steps
 * you need to walk to cut off all the trees. If you can't cut off all the
 * trees, output -1 in that situation.
 * 
 * You are guaranteed that no two trees have the same height and there is at
 * least one tree needs to be cut off.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * ⁠[1,2,3],
 * ⁠[0,0,4],
 * ⁠[7,6,5]
 * ]
 * Output: 6
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * ⁠[1,2,3],
 * ⁠[0,0,0],
 * ⁠[7,6,5]
 * ]
 * Output: -1
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 
 * [
 * ⁠[2,3,4],
 * ⁠[0,0,5],
 * ⁠[8,7,6]
 * ]
 * Output: 6
 * Explanation: You started from the point (0,0) and you can cut off the tree
 * in (0,0) directly without walking.
 * 
 * 
 * 
 * 
 * Hint: size of the given matrix will not exceed 50x50.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int cutOffTree(vector<vector<int>> &forest)
    {
        int m = forest.size(), n = forest[0].size();
        // {-height, index}
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (forest[i][j] > 1)
                {
                    pq.push({-forest[i][j], i * n + j});
                }
            }
        }
        if (pq.size() == 0)
            return 0;
        if (forest[0][0] == 0)
            return -1;
        int res = 0;
        int x = 0, y = 0;
        while (pq.size())
        {
            int to_x = pq.top().second / n, to_y = pq.top().second % n;
            pq.pop();
            int d = distance(forest, x, y, to_x, to_y);
            if (d == -1)
                return -1;
            res += d;
            x = to_x;
            y = to_y;
        }
        return res;
    }

    int distance(vector<vector<int>> &forest, int i, int j, int r, int c)
    {
        // using bfs to get shortest path
        int m = forest.size(), n = forest[0].size();
        bool visited[m][n] = {};
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        int steps = 0;
        while (q.size())
        {
            for (int k = q.size(); k > 0; --k)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (x == r && y == c)
                    return steps;
                for (auto &[dx, dy] : moves)
                {
                    int xx = x + dx, yy = y + dy;
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n && forest[xx][yy] && !visited[xx][yy])
                    {

                        q.push({xx, yy});
                        visited[xx][yy] = 1;
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};
// @lc code=end
