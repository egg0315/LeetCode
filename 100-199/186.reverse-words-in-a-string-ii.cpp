/*
 * @lc app=leetcode id=186 lang=cpp
 *
 * [186] Reverse Words in a String II
 * tag : string
 */
class Solution {
public:
  void reverseWords(vector<char> &s) {
    reverse(begin(s), end(s));
    auto start = s.begin();
    auto it = s.begin();
    while (it != s.end()) {
      while (it != s.end() && *it != ' ') {
        ++it;
      }
      reverse(start, it);
      if (it == s.end())
        break;
      ++it;
      start = it;
    }
  }
};
