/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */
class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    vector<vector<int>> g(n);
    vector<int> degree(n); // indegree
    for (auto &e : richer) {
      degree[e[1]]++;
      g[e[0]].push_back(e[1]);
    }
    vector<int> res(n);
    iota(res.begin(), res.end(), 0);

    // topological sort
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 0) {
        q.push(i);
      }
    }
    while (q.size()) {
      auto jeff = q.front();
      q.pop();
      for (auto &bill : g[jeff]) {
        if (quiet[res[bill]] > quiet[res[jeff]]) {
          res[bill] = res[jeff];
        }

        if (--degree[bill] == 0) {
          q.push(bill);
        }
      }
    }
    return res;
  }
};
