/*
 * @lc app=leetcode id=247 lang=cpp
 *
 * [247] Strobogrammatic Number II
 *
 * https://leetcode.com/problems/strobogrammatic-number-ii/description/
 *
 * algorithms
 * Medium (45.27%)
 * Likes:    270
 * Dislikes: 88
 * Total Accepted:    54.6K
 * Total Submissions: 120.4K
 * Testcase Example:  '2'
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * Example:
 *
 *
 * Input:  n = 2
 * Output: ["11","69","88","96"]
 *
 *
 */
class Solution {
public:
  // 11, 88, 00, 69,
  vector<string> findStrobogrammatic(int n) { return dfs(n, n); }

  vector<string> dfs(int n, int m) {
    if (n == 0) {
      return {""};
    }
    if (n == 1) {
      return {"0", "1", "8"};
    }
    vector<string> tmp = dfs(n - 2, m);
    vector<string> res;
    for (auto &s : tmp) {
      if (n != m) {
        res.push_back('0' + s + '0');
      }
      res.push_back('1' + s + '1');
      res.push_back('6' + s + '9');
      res.push_back('9' + s + '6');
      res.push_back('8' + s + '8');
    }
    return res;
  }
};
