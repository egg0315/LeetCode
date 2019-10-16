/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 * tag : ad hoc
 */
class Solution {
public:
  int countSegments(string s) {
    int res = 0;
    s.push_back(' ');
    for (int i = 1; i < s.size(); ++i)
      if (s[i] == ' ' && s[i - 1] != ' ')
        ++res;
    return res;
  }
};
