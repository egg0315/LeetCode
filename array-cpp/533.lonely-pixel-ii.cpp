/*
 * @lc app=leetcode id=533 lang=cpp
 *
 * [533] Lonely Pixel II
 */
class Solution {
public:
  int findBlackPixel(vector<vector<char>> &matrix, int N) {
    if (matrix.size() == 0)
      return 0;
    unordered_map<string, int> t;
    int m = matrix.size(), n = matrix[0].size();
    int col[n] = {};
    int row[m] = {};
    for (int i = 0; i < m; ++i) {
      string ro;
      for (int j = 0; j < n; ++j) {
        ro += matrix[i][j];
        row[i] += matrix[i][j] == 'B';
        col[j] += matrix[i][j] == 'B';
      }
      t[ro]++;
    }
    int res = 0;
    for (auto &[ro, cnt] : t) {
      if (cnt != N)
        continue;
      for (auto c : ro)
        cnt -= c == 'B';
      if (cnt)
        continue;
      for (int j = 0; j < n; ++j) {
        if (ro[j] == 'B' && col[j] == N) {
          res += N;
        }
      }
    }
    return res;
  }
};
