/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */
class Solution {
public:
  // bug : int overflow
  const long N = 1e6;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  inline long index(long i, long j) { return N * i + j; }
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source,
                        vector<int> &target) {
    return bfs(blocked, source, target) && bfs(blocked, target, source);
  }

  bool bfs(vector<vector<int>> &blocked, vector<int> &source,
           vector<int> &target) {
    unordered_set<long> wall;
    for (auto &b : blocked) {
      wall.insert(index(b[0], b[1]));
    }
    queue<pair<int, int>> q;
    q.push({source[0], source[1]});
    wall.insert(index(source[0], source[1]));
    int i = 0, j = 0;
    while (q.size()) {
      auto [i, j] = q.front();
      q.pop();
      if (i == target[0] && j == target[1])
        return true;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        long key = index(x, y);
        if (x >= 0 && x < N && y >= 0 && y < N &&
            wall.find(key) == wall.end()) {
          wall.insert(key);
          q.push({x, y});
        }
        if (wall.size() >= 20200)
          return true;
      }
    }
    return false;
  }
};
