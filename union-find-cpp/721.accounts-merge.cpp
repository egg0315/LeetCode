/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */
class Solution {
public:
  unordered_map<string, string> parent;
  unordered_map<string, string> owner;
  unordered_set<string> address;
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    vector<vector<string>> groups;

    for (auto &acc : accounts) {
      string name = acc[0];
      for (int i = 1; i < acc.size(); ++i) {
        owner[acc[i]] = name;
        parent[acc[i]] = acc[i];
        address.insert(acc[i]);
      }
      groups.push_back(vector<string>(acc.begin() + 1, acc.end()));
    }

    for (auto &group : groups) {
      for (int i = 1; i < group.size(); ++i) {
        join(group[i], group[i - 1]);
      }
    }

    unordered_map<string, vector<string>> output;

    for (auto addr : address) {
      output[find(addr)].push_back(addr);
    }

    vector<vector<string>> res;

    for (auto &[root, v] : output) {
      sort(v.begin(), v.end());
      vector<string> tmp = {owner[root]};
      copy(v.begin(), v.end(), back_inserter(tmp));
      res.push_back(tmp);
    }
    return res;
  }

  void join(string &p, string &q) {
    auto pid = find(p);
    auto qid = find(q);
    if (pid == qid)
      return;
    parent[pid] = qid;
  }

  string find(string &p) {
    string root = p;
    while (parent[root] != root) {
      root = parent[root];
    }
    string x = p;
    while (x != root) {
      string tmp = parent[x];
      parent[x] = root;
      x = tmp;
    }
    return root;
  }
};
