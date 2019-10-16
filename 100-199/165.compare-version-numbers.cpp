/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 * tag : string
 */
class Solution {
public:
  int compareVersion(string s1, string s2) {
    int p1 = 0, p2 = 0;
    while (p1 < s1.size() || p2 < s2.size()) {
      int v1 = 0, v2 = 0;
      while (p1 < s1.size() && s1[p1] != '.') {
        v1 = v1 * 10 + s1[p1++] - '0';
      }
      while (p2 < s2.size() && s2[p2] != '.') {
        v2 = v2 * 10 + s2[p2++] - '0';
      }
      //
      ++p1;
      ++p2;
      if (v1 < v2)
        return -1;
      else if (v1 > v2)
        return 1;
    }
    return 0;
  }
};
