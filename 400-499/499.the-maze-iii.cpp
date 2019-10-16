/*
 * @lc app=leetcode id=499 lang=cpp
 *
 * [499] The Maze III
 */

class Solution {
public:
  struct node {
    string move = "";
    int d = 0;
    int x = -1;
    int y = -1;

    bool operator()(const node &a, const node &b) {
      if (a.d != b.d)
        return a.d > b.d;
      else {
        return a.move > b.move;
      }
    }
  };
  // d l r u
  string dir = "dlru";
  int dx[4] = {1, 0, 0, -1};
  int dy[4] = {0, -1, 1, 0};
  const int INF = 1e8;

  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball,
                         vector<int> &hole) {
    priority_queue<node, vector<node>, node> pq;
    if (maze[hole[0]][hole[1]])
      return "impossible";
    string res = "impossible";
    int min_distance = INF;
    int m = maze.size(), n = maze[0].size();
    bool visited[m][n] = {};
    pq.push({"", 0, ball[0], ball[1]});
    visited[ball[0]][ball[1]] = 1;
    int x, y, distance;
    string move;

    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      distance = cur.d;
      if (distance >= min_distance)
        break;
      x = cur.x;
      y = cur.y;
      move = cur.move;
      visited[x][y] = 1;
      // try four directions
      for (int k = 0; k < 4; ++k) {
        int i = x;
        int j = y;
        int step = 0;
        string mm = move + dir[k];
        while (i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < m &&
               j + dy[k] < n && !maze[i + dx[k]][j + dy[k]]) {
          i += dx[k];
          j += dy[k];
          ++step;
          if (i == hole[0] && j == hole[1]) {
            if (distance + step < min_distance) {
              min_distance = distance + step;
              res = mm;
            }
            if (distance + step == min_distance) {
              res = min(res, mm);
            }
          }
        }
        if (!visited[i][j]) {
          pq.push({move + dir[k], distance + step, i, j});
        }
      }
    }
    return res;
  }
};
