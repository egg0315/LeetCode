/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 *
 * https://leetcode.com/problems/design-hit-counter/description/
 *
 * algorithms
 * Medium (60.08%)
 * Likes:    398
 * Dislikes: 42
 * Total Accepted:    51.1K
 * Total Submissions: 85K
 * Testcase Example:
 * '["HitCounter","hit","hit","hit","getHits","hit","getHits","getHits"]\n[[],[1],[2],[3],[4],[300],[300],[301]]'
 *
 * Design a hit counter which counts the number of hits received in the past 5
 * minutes.
 *
 * Each function accepts a timestamp parameter (in seconds granularity) and you
 * may assume that calls are being made to the system in chronological order
 * (ie, the timestamp is monotonically increasing). You may assume that the
 * earliest timestamp starts at 1.
 *
 * It is possible that several hits arrive roughly at the same time.
 *
 * Example:
 *
 *
 * HitCounter counter = new HitCounter();
 *
 * // hit at timestamp 1.
 * counter.hit(1);
 *
 * // hit at timestamp 2.
 * counter.hit(2);
 *
 * // hit at timestamp 3.
 * counter.hit(3);
 *
 * // get hits at timestamp 4, should return 3.
 * counter.getHits(4);
 *
 * // hit at timestamp 300.
 * counter.hit(300);
 *
 * // get hits at timestamp 300, should return 4.
 * counter.getHits(300);
 *
 * // get hits at timestamp 301, should return 3.
 * counter.getHits(301);
 *
 *
 * Follow up:
 * What if the number of hits per second could be very large? Does your design
 * scale?
 */
class HitCounter {
public:
  /** Initialize your data structure here. */
  HitCounter() { total = 0; }

  /** Record a hit.
      @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    while (q.size() && q.front().first <= timestamp - 300) {
      total -= q.front().second;
      q.pop();
    }
    if (q.size() && timestamp == q.back().first) {
      q.back().second++;
    } else {
      q.push({timestamp, 1});
    }
    ++total;
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    while (q.size() && q.front().first <= timestamp - 300) {
      total -= q.front().second;
      q.pop();
    }
    return total;
  }

private:
  queue<pair<int, int>> q;
  int total;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
