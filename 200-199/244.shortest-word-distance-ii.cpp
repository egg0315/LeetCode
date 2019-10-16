/*
 * @lc app=leetcode id=244 lang=cpp
 *
 * [244] Shortest Word Distance II
 */
class WordDistance {
public:
  unordered_map<string, vector<int>> m;
  WordDistance(vector<string> &words) {
    for (int i = 0; i < words.size(); ++i)
      m[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    int ret = INT_MAX;
    int i = 0, j = 0;
    while (i < m[word1].size() && j < m[word2].size()) {
      ret = min(ret, abs(m[word1][i] - m[word2][j]));
      m[word1][i] < m[word2][j] ? ++i : ++j;
    }
    return ret;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
