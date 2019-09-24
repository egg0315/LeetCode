/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/description/
 *
 * algorithms
 * Easy (67.36%)
 * Likes:    349
 * Dislikes: 40
 * Total Accepted:    87.6K
 * Total Submissions: 129.9K
 * Testcase Example:
 * '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'
 *
 * Given a stream of integers and a window size, calculate the moving average
 * of all integers in the sliding window.
 *
 * Example:
 *
 *
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 *
 *
 *
 *
 */
class MovingAverage {
public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    sz = size;
    total = 0.0;
  }

  double next(int val) {
    q.push(val);
    total += val;
    if (q.size() > sz) {
      total -= q.front();
      q.pop();
    }
    return total / q.size();
  }

private:
  int sz;
  queue<int> q;
  double total;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
