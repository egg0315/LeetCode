/*
 * @lc app=leetcode id=1066 lang=cpp
 *
 * [1066] Campus Bikes II
 * tag : dp, state compression
 */
class Solution {
public:
  const int INF = INT_MAX / 2;
  int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
    int n = workers.size();
    int m = bikes.size();

    vector<vector<int>> dp(n + 1, vector<int>(1 << m, INF));
    int res = INT_MAX;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int s = 1; s < (1 << m); ++s) {
        for (int j = 0; j < m; ++j) {
          if ((s & (1 << j)) == 0)
            continue;
          int prev = s ^ (1 << j);
          dp[i][s] =
              min(dp[i][s], dp[i - 1][prev] + dist(workers[i - 1], bikes[j]));
        }
        if (i == n) {
          res = min(res, dp[i][s]);
        }
      }
    }
    return res;
  }

  int dist(vector<int> &v1, vector<int> &v2) {
    return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
  }
};
