/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */
class Solution {
public:
  // 0: unvisited, 1: safe 2: unsafe, 3: undecide
  int visited[10001] = {};
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (!cycle(graph, i))
        res.push_back(i);
    }
    return res;
  }

  bool cycle(vector<vector<int>> &graph, int v) {
    if (visited[v])
      return visited[v] != 1;
    visited[v] = 3;
    int state = 1;
    for (auto u : graph[v]) {
      if (cycle(graph, u)) {
        state = 2;
        break;
      }
    }
    visited[v] = state;
    return state == 2;
  }
};
