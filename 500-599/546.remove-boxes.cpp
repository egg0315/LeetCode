/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */
class Solution {
public:
  int memo[101][101][101];

  int removeBoxes(vector<int> &v) {
    int n = v.size();
    return dfs(v, 0, n - 1, 0);
  }

  int dfs(vector<int> &v, int i, int j, int k) {
    if (i > j) {
      return 0;
    }
    if (memo[i][j][k]) {
      return memo[i][j][k];
    }
    while (i + 1 <= j && v[i + 1] == v[i]) {
      ++i;
      ++k;
    }
    int res = (k + 1) * (k + 1) + dfs(v, i + 1, j, 0);
    for (int m = i + 1; m <= j; ++m) {
      if (v[m] == v[i]) {
        res = max(res, dfs(v, i + 1, m - 1, 0) + dfs(v, m, j, k + 1));
      }
    }
    return memo[i][j][k] = res;
  }
};
