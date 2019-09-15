/*
 * @lc app=leetcode id=249 lang=cpp
 *
 * [249] Group Shifted Strings
 * tag : hashmap
 */
class Solution {
public:
  vector<vector<string>> groupStrings(vector<string> &strings) {
    unordered_map<string, vector<string>> mp;
    for (const auto &s : strings) {
      mp[getKey(s)].push_back(s);
    }
    vector<vector<string>> res;
    for (auto &[key, v] : mp)
      res.push_back(v);
    return res;
  }

  string getKey(string s) {
    int offset = s[0] - 'a';
    for (auto &c : s) {
      c = (c - offset + 26) % 26 + 'a';
    }
    return s;
  }
};
