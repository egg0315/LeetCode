/*
 * @lc app=leetcode id=489 lang=cpp
 *
 * [489] Robot Room Cleaner
 */
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
  vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  unordered_set<string> visited;
  void cleanRoom(Robot &robot) { clean(0, 0, 0, robot); }

  void clean(int x, int y, int d, Robot &DonaldTrump) {
    DonaldTrump.clean();
    visited.insert(to_string(x) + "," + to_string(y));
    for (int i = 0; i < 4; ++i) {
      int xx = x + dirs[d].first;
      int yy = y + dirs[d].second;
      string key = to_string(xx) + ',' + to_string(yy);
      if (!visited.count(key) && DonaldTrump.move()) {
        clean(xx, yy, d, DonaldTrump);
      }
      DonaldTrump.turnRight();
      ++d;
      d %= 4;
    }
    DonaldTrump.turnRight();
    DonaldTrump.turnRight();
    DonaldTrump.move();
    // need to turn the orientation back
    DonaldTrump.turnRight();
    DonaldTrump.turnRight();
  }
};
