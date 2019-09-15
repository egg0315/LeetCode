/*
 * @lc app=leetcode id=293 lang=cpp
 *
 * [293] Flip Game
 * tag : string
 */
class Solution {
public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> valid;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '+' && s[i - 1] == '+') {
        s[i] = s[i - 1] = '-';
        valid.push_back(s);
        s[i] = s[i - 1] = '+';
      }
    }
    return valid;
  }
};
