/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */
class Solution {
public:
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int shortestBridge(vector<vector<int>> &A) {

    // color first island to 2
    queue<pair<int, int>> q;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A[0].size(); ++j) {
        if (A[i][j]) {
          flood(A, i, j, 2, q);
          i = A.size();
          break;
        }
      }
    }
    // bfs flood to the other island
    int x, y;
    int step = 0;
    while (q.size()) {
      int len = q.size();
      for (int k = 0; k < len; ++k) {
        auto [x, y] = q.front();
        q.pop();
        for (auto &[dx, dy] : dirs) {
          int xx = x + dx, yy = y + dy;
          if (xx >= 0 && xx < A.size() && yy >= 0 && yy < A[0].size() &&
              A[xx][yy] != 2) {
            if (A[xx][yy] == 1)
              return step;
            A[xx][yy] = 2;
            q.push({xx, yy});
          }
        }
      }

      ++step;
    }
    return -1;
  }

  void flood(vector<vector<int>> &A, int i, int j, int color,
             queue<pair<int, int>> &q) {
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] != 1)
      return;
    A[i][j] = color;
    q.push({i, j});
    flood(A, i + 1, j, color, q);
    flood(A, i - 1, j, color, q);
    flood(A, i, j - 1, color, q);
    flood(A, i, j + 1, color, q);
  }
};
