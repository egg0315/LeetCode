/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 * tag: ad-hoc
 */
class Solution {
public:
  int lengthOfLastWord(string s) {
    int res = 0;
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ')
      --i;
    int len = 0;
    while (i >= 0 && s[i] != ' ') {
      --i;
      ++len;
    }
    return len;
  }
};
