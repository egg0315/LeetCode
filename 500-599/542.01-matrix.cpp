/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
class Solution {
public:
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
    vector<vector<int>> res(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!matrix[i][j]) {
          q.push({i, j});
          matrix[i][j] = 2;
        }
      }
    }
    int step = 0;
    int x, y;
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto [x, y] = q.front();
        q.pop();
        res[x][y] = step;
        for (auto &[dx, dy] : dirs) {
          if (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n &&
              matrix[x + dx][y + dy] != 2) {
            q.push({x + dx, y + dy});
            matrix[x + dx][y + dy] = 2;
          }
        }
      }
      ++step;
    }
    return res;
  }
};
