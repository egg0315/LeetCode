/*
 * @lc app=leetcode id=531 lang=cpp
 *
 * [531] Lonely Pixel I
 */
class Solution {
public:
  int findLonelyPixel(vector<vector<char>> &matrix) {
    if (matrix.size() == 0)
      return 0;
    int m = matrix.size(), n = matrix[0].size();
    int row[m] = {};
    int col[n] = {};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 'B') {
          row[i]++;
          col[j]++;
        }
      }
    }
    return min(count(row, row + m, 1), count(col, col + n, 1));
  }
};
