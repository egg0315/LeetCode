/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */
class Solution {
public:
  typedef unsigned int uint;
  uint dp[2][51][51] = {};
  const uint MOD = 1e9 + 7;
  int findPaths(int m, int n, int N, int r, int c) {
    for (int k = 1; k <= N; ++k) {
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          int p = k % 2;
          int q = (k - 1) % 2;
          dp[p][i][j] = (i == 0 ? 1 : dp[q][i - 1][j]) +
                        (j == 0 ? 1 : dp[q][i][j - 1]) +
                        (i == m - 1 ? 1 : dp[q][i + 1][j]) +
                        (j == n - 1 ? 1 : dp[q][i][j + 1]);
          dp[p][i][j] %= MOD;
        }
      }
    }
    return dp[N % 2][r][c];
  }
};
