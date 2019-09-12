/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
class Solution {
public:
  // unoptimized dijkstra
  // representation, and heap optimization
  int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    const int INF = 1e9;
    vector<int> d(N + 1, INF);
    d[K] = 0;
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < N; ++i) {
      // find cloest reached node
      int u = -1;
      for (int v = 1; v <= N; ++v) {
        if (d[v] != INF && !visited[v]) {
          if (u == -1 || d[v] < d[u]) {
            u = v;
          }
        }
      }
      if (u == -1)
        break;
      visited[u] = true;
      // update all u's neighbor
      int a, b, t;
      for (auto &edge : times) {
        a = edge[0];
        b = edge[1];
        t = edge[2];
        if (a == u && d[b] > d[a] + t) {
          d[b] = d[a] + t;
        }
      }
    }
    int time = *max_element(d.begin() + 1, d.end());
    return time == INF ? -1 : time;
  }
};
