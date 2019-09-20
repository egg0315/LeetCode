/*
 * @lc app=leetcode id=311 lang=cpp
 *
 * [311] Sparse Matrix Multiplication
 *
 * https://leetcode.com/problems/sparse-matrix-multiplication/description/
 *
 * algorithms
 * Medium (57.53%)
 * Likes:    307
 * Dislikes: 130
 * Total Accepted:    71.2K
 * Total Submissions: 123.6K
 * Testcase Example:  '[[1,0,0],[-1,0,3]]\n[[7,0,0],[0,0,0],[0,0,1]]'
 *
 * Given two sparse matrices A and B, return the result of AB.
 *
 * You may assume that A's column number is equal to B's row number.
 *
 * Example:
 *
 *
 * Input:
 *
 * A = [
 * ⁠ [ 1, 0, 0],
 * ⁠ [-1, 0, 3]
 * ]
 *
 * B = [
 * ⁠ [ 7, 0, 0 ],
 * ⁠ [ 0, 0, 0 ],
 * ⁠ [ 0, 0, 1 ]
 * ]
 *
 * Output:
 *
 * ⁠    |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
 * AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
 * ⁠                 | 0 0 1 |
 *
 *
 */
class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    int m = A.size(), K = A[0].size(), n = B[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));

    unordered_map<int, vector<pair<int, int>>> map_a;
    unordered_map<int, vector<pair<int, int>>> map_b;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < K; ++j)
        if (A[i][j])
          map_a[i].push_back({j, A[i][j]});

    for (int i = 0; i < K; ++i)
      for (int j = 0; j < n; ++j)
        if (B[i][j])
          map_b[i].push_back({j, B[i][j]});

    for (int i = 0; i < m; ++i)
      for (auto &[k, a] : map_a[i])
        for (auto &[j, b] : map_b[k])
          res[i][j] += a * b;
    return res;
  }
};
