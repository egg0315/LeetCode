/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
class Solution {
public:
  unordered_map<int, int> memo;
  int numTrees(int n) {
    if (n <= 1)
      return 1;
    if (memo.find(n) != memo.end())
      return memo[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += numTrees(i) * numTrees(n - 1 - i);
    }
    return memo[n] = sum;
  }
};
