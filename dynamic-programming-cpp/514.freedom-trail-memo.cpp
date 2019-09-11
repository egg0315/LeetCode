/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */
class Solution {
public:
  unordered_map<char, vector<int>> m;
  const int INF = 1e8;
  int memo[101][101];

  int findRotateSteps(string ring, string key) {
    // init
    for (int i = 0; i < 101; ++i)
      for (int j = 0; j < 101; ++j)
        memo[i][j] = INF;
    for (int i = 0; i < ring.size(); ++i)
      m[ring[i]].push_back(i);
    return dfs(ring, 0, key, 0) + key.size();
  }

  int dfs(string &ring, int j, string &key, int i) {
    if (i == key.size()) {
      return 0;
    }
    if (memo[i][j] != INF)
      return memo[i][j];
    int tmp = INF;
    for (auto k : m[key[i]]) {
      int a = abs(j - k);
      int b = ring.size() - a;
      tmp = min(dfs(ring, k, key, i + 1) + min(a, b), tmp);
    }
    return memo[i][j] = tmp;
  }
};
