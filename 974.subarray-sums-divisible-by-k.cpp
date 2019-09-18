/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */
class Solution {
public:
  int subarraysDivByK(vector<int> &A, int K) {
    int counter[K] = {};
    int res = 0;
    int presum = 0;
    counter[0] = 1;
    for (auto i : A) {
      presum = (i + presum) % K;
      if (presum < 0)
        presum += K;
      res += counter[presum];
      counter[presum]++;
    }
    return res;
  }
};
