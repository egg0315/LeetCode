/*
 * @lc app=leetcode id=1182 lang=cpp
 *
 * [1182] Shortest Distance to Target Color
 *
 * https://leetcode.com/problems/shortest-distance-to-target-color/description/
 *
 * algorithms
 * Medium (47.81%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    2K
 * Total Submissions: 4K
 * Testcase Example:  '[1,1,2,1,3,2,2,3,3]\n[[1,3],[2,2],[6,1]]'
 *
 * You are given an array colors, in which there are three colors: 1, 2 and 3.
 *
 * You are also given some queries. Each query consists of two integers i and
 * c, return the shortest distance between the given index i and the target
 * color c. If there is no solution return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
 * Output: [3,0,3]
 * Explanation:
 * The nearest 3 from index 1 is at index 4 (3 steps away).
 * The nearest 2 from index 2 is at index 2 itself (0 steps away).
 * The nearest 1 from index 6 is at index 3 (3 steps away).
 *
 *
 * Example 2:
 *
 *
 * Input: colors = [1,2], queries = [[0,3]]
 * Output: [-1]
 * Explanation: There is no 3 in the array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= colors.length <= 5*10^4
 * 1 <= colors[i] <= 3
 * 1 <= queries.length <= 5*10^4
 * queries[i].length == 2
 * 0 <= queries[i][0] < colors.length
 * 1 <= queries[i][1] <= 3
 *
 *
 */
class Solution {
public:
  const int INF = 1e8;
  vector<int> shortestDistanceColor(vector<int> &colors,
                                    vector<vector<int>> &queries) {
    int n = colors.size();
    vector<vector<int>> cache(3, vector<int>(n, 0));
    int next[3] = {INF, INF, INF};
    for (int i = n - 1; i >= 0; --i) {
      next[colors[i] - 1] = i;
      for (int k = 0; k < 3; ++k) {
        cache[k][i] = next[k];
      }
    }
    int prev[3] = {-INF, -INF, -INF};
    for (int i = 0; i < n; ++i) {
      prev[colors[i] - 1] = i;
      for (int k = 0; k < 3; ++k) {
        if (abs(i - prev[k]) < abs(cache[k][i] - i)) {
          cache[k][i] = prev[k];
        }
      }
    }

    vector<int> res;
    for (auto &q : queries) {
      int c = q[1], start = q[0];
      if (cache[c - 1][start] > n) {
        res.push_back(-1);
      } else {
        res.push_back(abs(cache[c - 1][start] - start));
      }
    }
    return res;
  }
};
