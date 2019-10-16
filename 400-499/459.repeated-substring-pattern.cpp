/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 * tag : string
 */
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    return (s + s).substr(1, 2 * s.size() - 1).find(s) != s.size() - 1;
  }
};
