/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */
class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    vector<vector<int>> g(N);
    for (auto &e : dislikes) {
      g[e[0] - 1].push_back(e[1] - 1);
      g[e[1] - 1].push_back(e[0] - 1);
    }
    // color the graph
    vector<int> color(N, -1);
    for (auto i = 0; i < N; ++i) {
      if (color[i] == -1) {
        color[i] = 0;
        if (!dfs(g, i, color)) {
          return false;
        }
      }
    }
    return true;
  }

  bool dfs(vector<vector<int>> &g, int i, vector<int> &color) {
    int n = g.size();
    for (auto v : g[i]) {
      if (color[v] == -1) {
        color[v] = 1 - color[i];
        if (!dfs(g, v, color))
          return false;
      } else if (color[v] == color[i]) {
        return false;
      }
    }
    return true;
  }
};
