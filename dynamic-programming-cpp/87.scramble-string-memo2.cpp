/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */
class Solution {
public:
  int dp[31][31][31][31];
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    if (s1 == s2)
      return true;
    int n = s1.size();
    memset(dp, -1, sizeof(dp));
    return dfs(s1, 0, n - 1, s2, 0, n - 1);
  }

  bool dfs(string &s1, int i1, int j1, string &s2, int i2, int j2) {
    if (dp[i1][j1][i2][j2] != -1)
      return dp[i1][j1][i2][j2];
    int sz = j1 - i1 + 1;
    if (s1.substr(i1, sz) == s2.substr(i2, sz))
      return dp[i1][j1][i2][j2] = 1;
    if (!check(s1, i1, j1, s2, i2, j2))
      return dp[i1][j1][i2][j2] = 0;
    // break at [i1, i1+k-1]
    bool res = false;
    for (int k = 1; k < sz; ++k) {
      if (dfs(s1, i1, i1 + k - 1, s2, i2, i2 + k - 1) &&
          dfs(s1, i1 + k, j1, s2, i2 + k, j2))
        return dp[i1][j1][i2][j2] = 1;
      if (dfs(s1, i1, i1 + k - 1, s2, j2 - k + 1, j2) &&
          dfs(s1, i1 + k, j1, s2, i2, j2 - k))
        return dp[i1][j1][i2][j2] = 1;
    }

    return dp[i1][j1][i2][j2] = 0;
  }

  bool check(string &s1, int i1, int j1, string &s2, int i2, int j2) {
    vector<int> v1(256);
    vector<int> v2(256);
    for (int i = i1; i <= j1; ++i)
      v1[s1[i]]++;
    for (int i = i2; i <= j2; ++i)
      v2[s2[i]]++;
    return v1 == v2;
  }
};
