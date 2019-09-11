/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
 * Note : shortest distance is not necessary first arrival of destination
 *  also, dont mark visited until start from here
 */
class Solution {
public:
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  const int INF = 1e8;
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
                       vector<int> &dest) {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                   greater<>>
        pq;
    if (maze[dest[0]][dest[1]])
      return -1;
    int res = INF;
    int m = maze.size(), n = maze[0].size();
    bool visited[m][n] = {};
    pq.push({0, {start[0], start[1]}});
    visited[start[0]][start[1]] = 1;
    int x, y, distance;
    while (!pq.empty()) {
      distance = pq.top().first;
      if (distance >= res)
        break;
      x = pq.top().second[0];
      y = pq.top().second[1];
      pq.pop();

      visited[x][y] = 1;
      // try four directions
      for (int k = 0; k < 4; ++k) {
        int i = x;
        int j = y;
        int step = 0;
        while (i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < m &&
               j + dy[k] < n && !maze[i + dx[k]][j + dy[k]]) {
          i += dx[k];
          j += dy[k];
          ++step;
        }
        if (i == dest[0] && j == dest[1]) {
          res = min(INF, distance + step);
        }
        if (!visited[i][j]) {
          pq.push({distance + step, {i, j}});
        }
      }
    }
    return res == INF ? -1 : res;
  }
};
