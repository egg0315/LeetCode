/*
 * @lc app=leetcode id=286 lang=cpp
 *
 * [286] Walls and Gates
 *
 * https://leetcode.com/problems/walls-and-gates/description/
 *
 * algorithms
 * Medium (50.47%)
 * Likes:    721
 * Dislikes: 10
 * Total Accepted:    85.2K
 * Total Submissions: 168.5K
 * Testcase Example:
 * '[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]'
 *
 * You are given a m x n 2D grid initialized with these three possible
 * values.
 *
 *
 * -1 - A wall or an obstacle.
 * 0 - A gate.
 * INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647
 * to represent INF as you may assume that the distance to a gate is less than
 * 2147483647.
 *
 *
 * Fill each empty room with the distance to its nearest gate. If it is
 * impossible to reach a gate, it should be filled with INF.
 *
 * Example: 
 *
 * Given the 2D grid:
 *
 *
 * INF  -1  0  INF
 * INF INF INF  -1
 * INF  -1 INF  -1
 * ⁠ 0  -1 INF INF
 *
 *
 * After running your function, the 2D grid should be:
 *
 *
 * ⁠ 3  -1   0   1
 * ⁠ 2   2   1  -1
 * ⁠ 1  -1   2  -1
 * ⁠ 0  -1   3   4
 *
 *
 */
class Solution {
public:
  const int INF = INT_MAX;
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void wallsAndGates(vector<vector<int>> &rooms) {
    int m = rooms.size(), n = m ? rooms[0].size() : 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rooms[i][j] == 0)
          q.push({i, j});
      }
    }
    int step = 1;
    int x, y, xx, yy;
    while (q.size()) {
      for (int k = q.size(); k > 0; --k) {
        auto [x, y] = q.front();
        q.pop();
        for (auto &[dx, dy] : dirs) {
          xx = x + dx;
          yy = y + dy;
          if (xx >= 0 && xx < m && yy >= 0 && yy < n && rooms[xx][yy] == INF) {
            q.push({xx, yy});
            rooms[xx][yy] = step;
          }
        }
      }
      ++step;
    }
  }
};
