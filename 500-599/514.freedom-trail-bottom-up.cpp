/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */
class Solution {
public:
  unordered_map<char, vector<int>> mp;
  const int INF = 1e8;
  int findRotateSteps(string ring, string key) {
    int m = key.size(), n = ring.size();
    for (int i = 0; i < ring.size(); ++i)
      mp[ring[i]].push_back(i);
    vector<vector<int>> dp(m + 1, vector<int>(n, INF));
    for (int j = 0; j < n; ++j)
      dp[m][j] = 0;
    int res = INF;
    // revisit
    for (int k = m - 1; k >= 0; --k) {
      for (int j = 0; j < n; ++j) {
        for (auto i : mp[key[k]]) {
          int dif = abs(i - j);
          int move = min(dif, n - dif);
          dp[k][j] = min(dp[k][j], dp[k + 1][i] + move);
        }
      }
    }
    return dp[0][0] + m;
  }
};
