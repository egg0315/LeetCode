/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 * tag : string, two pointer
 */
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    // find odd length palindrome
    int ret = 0;
    string pal;
    for (int i = 0; i < n; ++i) {
      int l = i, r = i;
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
      }
      if (ret < r - l - 1) {
        ret = r - l - 1;
        pal = s.substr(l + 1, ret);
      }
    }
    // even length
    for (int i = 0; i + 1 < n; ++i) {
      int l = i, r = i + 1;
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
      }
      if (ret < r - l - 1) {
        ret = r - l - 1;
        pal = s.substr(l + 1, ret);
      }
    }

    return pal;
  }
};
