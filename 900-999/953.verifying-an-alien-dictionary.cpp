/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */
class Solution {
public:
  unordered_map<char, int> w;
  bool isAlienSorted(vector<string> &words, string order) {
    for (int i = 0; i < order.size(); ++i) {
      w[order[i]] = i;
    }
    for (int i = 1; i < words.size(); ++i) {
      if (!compare(words[i - 1], words[i]))
        return false;
    }
    return true;
  }

  bool compare(string &a, string &b) {
    for (int i = 0; i < min(a.size(), b.size()); ++i) {
      if (w[a[i]] < w[b[i]])
        return true;
      else if (w[a[i]] > w[b[i]])
        return false;
    }
    return a.size() < b.size();
  }
};
