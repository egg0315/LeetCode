/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */
class Solution {
public:
  // dfs + memo is a little bit slow
  int memo[1001][1001];
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    memset(memo, 0, sizeof(memo));
    int res = 1;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        res = max(res, dfs(matrix, i, j));
      }
    }
    return res;
  }

  int dfs(vector<vector<int>> &matrix, int i, int j) {
    int m = matrix.size(), n = matrix[0].size();
    if (memo[i][j]) {
      return memo[i][j];
    }
    int tmp = 1;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] > matrix[i][j]) {
        tmp = max(tmp, 1 + dfs(matrix, x, y));
      }
    }
    return memo[i][j] = tmp;
  }
};
