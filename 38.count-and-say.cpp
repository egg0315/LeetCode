/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 * tag : implementation
 */
class Solution {
public:
  string countAndSay(int n) {
    string cur = "1";
    while (n > 1) {
      string next = say(cur);
      cur = next;
      --n;
    }
    return cur;
  }

  string say(string &s) {
    string next;
    char c = s[0];
    int count = 1;
    int i = 1;
    for (; i <= s.size(); ++i) {
      if (i == s.size() || s[i] != c) {
        next += to_string(count) + c;
        c = s[i];
        count = 1;
      } else {
        ++count;
      }
    }
    return next;
  }
};
