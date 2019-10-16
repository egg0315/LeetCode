/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */
class Solution {
public:
  unordered_map<string, string> mp;
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    for (auto &s : allowed) {
      string key = s.substr(0, 2);
      mp[key] += s[2];
    }

    return dfs(bottom, 1, "");
  }

  bool dfs(string &s, int i, string next) {
    if (s.size() == 1)
      return true;
    if (i == s.size()) {
      return dfs(next, 1, "");
    }
    string key = s.substr(i - 1, 2);
    for (auto &c : mp[key]) {
      if (dfs(s, i + 1, next + c))
        return true;
    }
    return false;
  }
};
