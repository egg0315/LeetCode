/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
      return false;
    int m = s1.size();
    int n = s2.size();
    // s1[0,i-1], s2[0,j-1]
    bool dp[m + 1][n + 1] = {};
    dp[0][0] = true;
    for (int j = 1; j <= n; ++j) {
      dp[0][j] = (s2[j - 1] == s3[j - 1] && dp[0][j - 1]);
    }
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = (s1[i - 1] == s3[i - 1] && dp[i - 1][0]);
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        char c = s3[i + j - 1];
        dp[i][j] = (s1[i - 1] == c && dp[i - 1][j]) ||
                   (s2[j - 1] == c && dp[i][j - 1]);
      }
    }
    return dp[m][n];
  }
};
