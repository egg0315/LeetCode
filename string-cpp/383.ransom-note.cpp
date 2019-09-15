/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 * tag : stl, string
 */
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> v1(26, 0);
    vector<int> v2(26, 0);
    for (auto &c : magazine)
      ++v1[c - 'a'];
    for (auto &c : ransomNote)
      ++v2[c - 'a'];
    vector<int> diff;
    transform(begin(v1), end(v1), begin(v2), back_inserter(diff),
              [](int x, int y) { return x - y; });
    return all_of(begin(diff), end(diff), [](int x) { return x >= 0; });
  }
};
