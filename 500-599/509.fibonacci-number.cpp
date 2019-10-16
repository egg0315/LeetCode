/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
class Solution {
public:
  int fib(int N) {
    if (N < 2)
      return N;
    long a = 0;
    long b = 1;
    for (int i = 0; i < N; ++i) {
      a += b;
      swap(a, b);
    }
    return a;
  }
};
