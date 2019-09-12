/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */
class Solution {
public:
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int largestIsland(vector<vector<int>> &grid) {
    int color = 2;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid.size(); ++j) {
        if (grid[i][j] == 1) {
          flood(grid, i, j, color++);
        }
      }
    }
    int res = 0;
    unordered_map<int, int> area;
    for (auto &row : grid) {
      for (auto &c : row) {
        if (c) {
          area[c]++;
          res = max(res, area[c]);
        }
      }
    }

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 0) {
          set<int> used;
          int tmp = 1;
          // count four potential connectable island
          for (auto &[dx, dy] : dirs) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                grid[x][y] != 0 && !used.count(grid[x][y])) {
              tmp += area[grid[x][y]];
              used.insert(grid[x][y]);
            }
          }
          res = max(res, tmp);
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
