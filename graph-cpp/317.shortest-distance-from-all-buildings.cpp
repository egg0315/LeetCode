/*
 * @lc app=leetcode id=317 lang=cpp
 *
 * [317] Shortest Distance from All Buildings
 *
 * https://leetcode.com/problems/shortest-distance-from-all-buildings/description/
 *
 * algorithms
 * Hard (38.87%)
 * Likes:    530
 * Dislikes: 30
 * Total Accepted:    47.6K
 * Total Submissions: 122.1K
 * Testcase Example:  '[[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]'
 *
 * You want to build a house on an empty land which reaches all buildings in
 * the shortest amount of distance. You can only move up, down, left and right.
 * You are given a 2D grid of values 0, 1 or 2, where:
 *
 *
 * Each 0 marks an empty land which you can pass by freely.
 * Each 1 marks a building which you cannot pass through.
 * Each 2 marks an obstacle which you cannot pass through.
 *
 *
 * Example:
 *
 *
 * Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
 *
 * 1 - 0 - 2 - 0 - 1
 * |   |   |   |   |
 * 0 - 0 - 0 - 0 - 0
 * |   |   |   |   |
 * 0 - 0 - 1 - 0 - 0
 *
 * Output: 7
 *
 * Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle
 * at (0,2),
 * ⁠            the point (1,2) is an ideal empty land to build a house, as
 * the total travel distance of 3+3+1=7 is minimal. So return 7.
 *
 * Note:
 * There will be at least one building. If it is not possible to build such
 * house according to the above rules, return -1.
 *
 */
class Solution {
public:
  int sum[101][101] = {};
  const int INF = 1e8;
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  int shortestDistance(vector<vector<int>> &grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          auto d = bfs(grid, i, j);
          for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
              if (d[i][j] == INF || sum[i][j] == INF) {
                sum[i][j] = INF;
              } else {
                sum[i][j] += d[i][j];
              }
            }
          }
        }
      }
    }
    // pick a spot
    int res = INF;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0 && sum[i][j] != INF) {
          res = min(res, sum[i][j]);
        }
      }
    }
    return res == INF ? -1 : res;
  }

  vector<vector<int>> bfs(vector<vector<int>> &grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dst(m, vector<int>(n, INF));
    queue<pair<int, int>> q;
    q.emplace(i, j);
    dst[i][j] = 0;
    int step = 0, x, y, xx, yy;

    while (!q.empty()) {
      ++step;
      for (int k = q.size(); k > 0; --k) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (auto &[dx, dy] : dirs) {
          xx = x + dx;
          yy = y + dy;
          if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == 0 &&
              dst[xx][yy] == INF &&
              sum[xx][yy] != INF) { // this line skips unreachable positions
            dst[xx][yy] = step;
            q.emplace(xx, yy);
          }
        }
      }
    }
    return dst;
  }
};
