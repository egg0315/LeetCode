/*
 * @lc app=leetcode id=159 lang=cpp
 *
 * [159] Longest Substring with At Most Two Distinct Characters
 * tag : two pointer
 */
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size();
    int distinct = 0;
    int i = 0, res = 0;
    unordered_map<char, int> count;
    for (int j = 0; j < n; ++j) {
      if (count[s[j]]++ == 0) {
        ++distinct;
      }
      if (distinct <= 2) {
        res = max(res, j - i + 1);
      }
      while (distinct > 2) {
        if (--count[s[i++]] == 0) {
          --distinct;
        }
      }
    }
    return res;
  }
};
