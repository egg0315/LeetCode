/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    // flood fill
    int color = 2;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          flood(grid, i, j, color++);
        }
      }
    }
    int res = 0;
    unordered_map<int, int> count;
    for (auto &row : grid) {
      for (auto &c : row) {
        if (c != 0) {
          res = max(res, ++count[c]);
        }
      }
    }
    return res;
  }

  void flood(vector<vector<int>> &grid, int i, int j, int color) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] != 1)
      return;
    grid[i][j] = color;
    flood(grid, i + 1, j, color);
    flood(grid, i - 1, j, color);
    flood(grid, i, j + 1, color);
    flood(grid, i, j - 1, color);
  }
};
