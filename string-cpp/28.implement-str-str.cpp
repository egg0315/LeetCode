/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 * tag : string, KMP, rolling hash
 */
class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    if (m == 0)
      return 0;
    for (int i = 0; i + m - 1 < n; ++i) {
      if (haystack.substr(i, m) == needle) {
        return i;
      }
    }
    return -1;
  }
};
