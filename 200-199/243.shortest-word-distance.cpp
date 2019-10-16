/*
 * @lc app=leetcode id=243 lang=cpp
 *
 * [243] Shortest Word Distance
 * tag : hashmap
 */
class Solution {
public:
  int shortestDistance(vector<string> &words, string word1, string word2) {
    unordered_map<string, int> m;
    int ret = INT_MAX;
    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == word1 && m.find(word2) != m.end()) {
        ret = min(ret, i - m[word2]);
      } else if (words[i] == word2 && m.find(word1) != m.end()) {
        ret = min(ret, i - m[word1]);
      }
      m[words[i]] = i;
    }
    return ret;
  }
};
