/*
 * @lc app=leetcode id=573 lang=cpp
 *
 * [573] Squirrel Simulation
 *
 * https://leetcode.com/problems/squirrel-simulation/description/
 *
 * algorithms
 * Medium (54.42%)
 * Likes:    109
 * Dislikes: 17
 * Total Accepted:    6.4K
 * Total Submissions: 11.8K
 * Testcase Example:  '5\n7\n[2,2]\n[4,4]\n[[3,0], [2,5]]'
 *
 * There's a tree, a squirrel, and several nuts. Positions are represented by
 * the cells in a 2D grid. Your goal is to find the minimal distance for the
 * squirrel to collect all the nuts and put them under the tree one by one. The
 * squirrel can only take at most one nut at one time and can move in four
 * directions - up, down, left and right, to the adjacent cell. The distance is
 * represented by the number of moves.
 * Example 1:
 *
 *
 * Input:
 * Height : 5
 * Width : 7
 * Tree position : [2,2]
 * Squirrel : [4,4]
 * Nuts : [[3,0], [2,5]]
 * Output: 12
 * Explanation:
 * ​​​​​
 *
 *
 * Note:
 *
 *
 * All given positions won't overlap.
 * The squirrel can take at most one nut at one time.
 * The given positions of nuts have no order.
 * Height and width are positive integers. 3 <= height * width <= 10,000.
 * The given positions contain at least one nut, only one tree and one
 * squirrel.
 *
 *
 */
class Solution {
public:
  int minDistance(int height, int width, vector<int> &tree,
                  vector<int> &squirrel, vector<vector<int>> &nuts) {
    // to minimize distance
    // need to maximize distance(nut[i], tree) - distance(nut[i], squ)
    int n = nuts.size();
    int d_t[n] = {};
    int d_s[n] = {};
    int k = -1; // first nut
    int minn = INT_MIN;
    for (int i = 0; i < n; ++i) {
      d_t[i] = dist(nuts[i], tree);
      d_s[i] = dist(nuts[i], squirrel);
      if (minn < d_t[i] - d_s[i]) {
        minn = d_t[i] - d_s[i];
        k = i;
      }
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
      total += (i == k) ? d_s[i] + d_t[i] : 2 * d_t[i];
    }
    return total;
  }

  int dist(vector<int> &v1, vector<int> &v2) {
    return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
  }
};
