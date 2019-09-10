/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
    if (matrix.size() == 0)
      return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> P(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      q.push({0, i});
      P[0][i] = true;
    }
    for (int i = 1; i < m; ++i) {
      q.push({i, 0});
      P[i][0] = true;
    }
    flood(matrix, q, P);
    vector<vector<bool>> A(m, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
      q.push({m - 1, i});
      A[m - 1][i] = true;
    }
    for (int i = 0; i < m - 1; ++i) {
      q.push({i, n - 1});
      A[i][n - 1] = true;
    }
    flood(matrix, q, A);

    // find common
    vector<vector<int>> res;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (P[i][j] && A[i][j])
          res.push_back({i, j});
      }
    }
    return res;
  }

  void flood(vector<vector<int>> &matrix, queue<pair<int, int>> &q,
             vector<vector<bool>> &v) {
    int m = v.size();
    int n = v[0].size();
    int x, y, i, j;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
      x = q.front().first;
      y = q.front().second;
      q.pop();
      for (int k = 0; k < 4; ++k) {
        i = x + dx[k];
        j = y + dy[k];
        if (i >= 0 && i < m && j >= 0 && j < n && !v[i][j] &&
            matrix[i][j] >= matrix[x][y]) {
          q.push({i, j});
          v[i][j] = true;
        }
      }
    }
  }
};
