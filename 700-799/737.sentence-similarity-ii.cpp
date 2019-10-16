/*
 * @lc app=leetcode id=737 lang=cpp
 *
 * [737] Sentence Similarity II
 */
class Solution {
public:
  unordered_map<string, string> parent;
  bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2,
                              vector<vector<string>> &pairs) {
    if (words1.size() != words2.size())
      return false;
    for (auto &s : words1)
      parent[s] = s;
    for (auto &s : words2)
      parent[s] = s;
    for (auto &pair : pairs) {
      parent[pair[0]] = pair[0];
      parent[pair[1]] = pair[1];
    }

    for (auto &pair : pairs) {
      join(pair[0], pair[1]);
    }

    for (int i = 0; i < words1.size(); ++i) {
      if (find(words1[i]) != find(words2[i]))
        return false;
    }
    return true;
  }

  void join(string &p, string &q) {
    string pid = find(p);
    string qid = find(q);
    if (pid == qid)
      return;
    parent[pid] = qid;
  }

  string find(string &p) {
    string r = p;
    while (parent[r] != r) {
      r = parent[r];
    }
    string x = p;
    while (x != p) {
      string tmp = parent[x];
      parent[x] = r;
      x = tmp;
    }
    return r;
  }
};
