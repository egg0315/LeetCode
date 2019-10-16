/*
 * @lc app=leetcode id=439 lang=cpp
 *
 * [439] Ternary Expression Parser
 * Note : this is more efficient than backwards pattern matching
 */
class Solution {
public:
  // recursive from back
  // more elegant one

  string parseTernary(string s) {
    int i = 0;
    return parse(s, i);
  }

  string parse(string &s, int &i) {
    char condition = s[i];
    if (i + 1 < s.size() && s[i + 1] == '?') {
      i += 2;
      string a = parse(s, i);
      string b = parse(s, ++i);
      return condition == 'T' ? a : b;
    }
    return s.substr(i++, 1);
  }
};
