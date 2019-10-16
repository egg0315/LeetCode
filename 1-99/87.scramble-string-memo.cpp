/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */
class Solution {
public:
  unordered_map<string, bool> mp;
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    if (s1 == s2)
      return true;
    if (s1.size() == 1)
      return s1 == s2;
    string key = s1 + "%" + s2; // hasing string is slow
    if (mp.find(key) != mp.end())
      return mp[key];
    // prune improve from 124ms to 4ms
    if (!anagram(s1, s2))
      return mp[key] = false;
    int n = s1.size();
    for (int i = 1; i < n; ++i) {
      // two cases
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i))) {
        return mp[key] = true;
      }
      if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
          isScramble(s1.substr(i), s2.substr(0, n - i))) {
        return mp[key] = true;
      }
    }
    return mp[key] = false;
  }

  bool anagram(string &a, string &b) {
    vector<int> v1(256);
    vector<int> v2(256);
    for (auto &c : a)
      v1[c]++;
    for (auto &c : b)
      v2[c]++;
    return v1 == v2;
  }
};
