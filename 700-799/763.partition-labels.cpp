/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> loc(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      loc[s[i] - 'a'] = i;
    }
    vector<int> res;
    int start = 0, n = s.size();
    while (start < n) {
      int end = loc[s[start] - 'a'];
      for (int i = start; i <= end; ++i) {
        end = max(end, loc[s[i] - 'a']);
      }
      res.push_back(end - start + 1);
      start = end + 1;
    }
    return res;
  }
};
