/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int m = p.size();
    vector<int> res;
    int need[26] = {};
    for (auto &c : p) {
      ++need[c - 'a'];
    }
    for (int i = 0; i < s.size(); ++i) {
      --need[s[i] - 'a'];
      if (i >= m) {
        ++need[s[i - m] - 'a'];
      }
      if (all_of(need, need + 26, [](int x) { return x == 0; })) {
        res.push_back(i - m + 1);
      }
    }
    return res;
  }
};
