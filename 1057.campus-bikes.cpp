/*
 * @lc app=leetcode id=1057 lang=cpp
 *
 * [1057] Campus Bikes
 */
class Solution {
public:
  vector<int> assignBikes(vector<vector<int>> &workers,
                          vector<vector<int>> &bikes) {
    int m = bikes.size();
    int n = workers.size();
    vector<vector<pair<int, int>>> pairs(2001);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int d =
            abs(workers[j][0] - bikes[i][0]) + abs(workers[j][1] - bikes[i][1]);
        pairs[d].push_back({j, i});
      }
    }
    int worker = n;
    vector<bool> used(m, false);
    vector<int> assign(n, -1);
    for (int i = 0; i < pairs.size(); ++i) {
      for (auto &[w, b] : pairs[i]) {
        if (!used[b] && assign[w] == -1) {
          assign[w] = b;
          used[b] = true;
          --worker;
        }
        if (worker == 0)
          return assign;
      }
    }
    return assign;
  }
};
