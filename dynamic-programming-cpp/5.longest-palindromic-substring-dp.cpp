/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
public:
  string longestPalindrome(string s) {
    if (s.size() < 2)
      return s;
    int n = s.size();
    bool dp[n][n] = {};
    string pal;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (i == j)
          dp[i][i] = true;
        else if (j - i == 1)
          dp[i][j] = s[i] == s[j];
        else {
          dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
        }
        if (dp[i][j] && j - i + 1 > pal.size()) {
          pal = s.substr(i, j - i + 1);
        }
      }
    }
    return pal;
  }
};
