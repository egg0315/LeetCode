/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 * tag : string, implementation
 */
class Solution {
public:
  bool detectCapitalUse(string word) {
    string s1 = word;
    for (auto &c : s1)
      c = toupper(c);
    string s2 = word;
    for (auto &c : s2)
      c = tolower(c);
    string s3 = word;
    for (auto &c : s3)
      c = tolower(c);
    s3[0] = toupper(s3[0]);
    return s1 == word || s2 == word || s3 == word;
  }
};
