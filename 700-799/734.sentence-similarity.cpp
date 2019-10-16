/*
 * @lc app=leetcode id=734 lang=cpp
 *
 * [734] Sentence Similarity
 */
class Solution {
public:
  unordered_map<string, vector<string>> mp;

  bool areSentencesSimilar(vector<string> &v1, vector<string> &v2,
                           vector<vector<string>> &pairs) {
    if (v1.size() != v2.size())
      return false;
    for (auto &pair : pairs) {
      mp[pair[0]].push_back(pair[1]);
      mp[pair[1]].push_back(pair[0]);
    }
    for (int i = 0; i < v1.size(); ++i) {
      if (v1[i] == v2[i])
        continue;
      if (count(mp[v1[i]].begin(), mp[v1[i]].end(), v2[i]) == 0)
        return false;
    }
    return true;
  }
};
