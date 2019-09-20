/*
 * @lc app=leetcode id=1055 lang=cpp
 *
 * [1055] Shortest Way to Form String
 *
 * https://leetcode.com/problems/shortest-way-to-form-string/description/
 *
 * algorithms
 * Medium (58.99%)
 * Likes:    104
 * Dislikes: 6
 * Total Accepted:    6.2K
 * Total Submissions: 10.6K
 * Testcase Example:  '"abc"\n"abcbc"'
 *
 * From any string, we can form a subsequence of that string by deleting some
 * number of characters (possibly no deletions).
 *
 * Given two strings source and target, return the minimum number of
 * subsequences of source such that their concatenation equals target. If the
 * task is impossible, return -1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: source = "abc", target = "abcbc"
 * Output: 2
 * Explanation: The target "abcbc" can be formed by "abc" and "bc", which are
 * subsequences of source "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: source = "abc", target = "acdbc"
 * Output: -1
 * Explanation: The target string cannot be constructed from the subsequences
 * of source string due to the character "d" in target string.
 *
 *
 * Example 3:
 *
 *
 * Input: source = "xyz", target = "xzyxz"
 * Output: 3
 * Explanation: The target string can be constructed as follows "xz" + "y" +
 * "xz".
 *
 *
 * Constraints:
 *
 *
 * Both the source and target strings consist of only lowercase English letters
 * from "a"-"z".
 * The lengths of source and target string are between 1 and 1000.
 *
 */
class Solution {
public:
  int shortestWay(string s, string t) {
    int m = s.size();
    // build map
    vector<vector<int>> map(26, vector<int>(m, -1));
    // build graph 26 * M
    for (int i = 0; i < 26; ++i) {
      char c = i + 'a';
      int pre = -1;
      for (int j = m - 1; j >= 0; --j) {
        if (s[j] == c) {
          pre = j;
        }
        map[i][j] = pre;
      }
    }
    // O(N)
    int i = 0, j = 0, res = 1;
    while (i < t.size()) {
      if (map[t[i] - 'a'][0] == -1)
        return -1;
      if (j >= m || map[t[i] - 'a'][j] == -1) {
        ++res;
        j = 0;
      } else {
        j = map[t[i] - 'a'][j] + 1;
        ++i;
      }
    }
    return res;
  }
};
