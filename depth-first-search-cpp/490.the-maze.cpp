/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 * Note: BFS is better because of follow ups, to practice DFS
 */
class Solution {
public:
  bool visited[101][101][4];
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  bool hasPath(vector<vector<int>> &maze, vector<int> &start,
               vector<int> &destination) {
    memset(visited, 0, sizeof(visited));
    int m = maze.size(), n = maze[0].size();
    for (int i = 0; i < 4; ++i) {
      if (dfs(maze, start, destination))
        return true;
    }
    return false;
  }

  bool dfs(vector<vector<int>> &maze, vector<int> &s, vector<int> &e) {
    if (s == e)
      return true;
    int m = maze.size(), n = maze[0].size();
    for (int k = 0; k < 4; ++k) {
      auto pos = s;
      if (visited[pos[0]][pos[1]][k])
        continue;
      visited[pos[0]][pos[1]][k] = true;
      auto x = pos[0] + dx[k], y = pos[1] + dy[k];
      while (x >= 0 && x < m && y >= 0 && y < n && !maze[x][y]) {
        pos[0] = x;
        pos[1] = y;
        x += dx[k];
        y += dy[k];
      }
      if (dfs(maze, pos, e))
        return true;
    }
    return false;
  }
};
