/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    dfs(rooms, visited, 0);
    for (auto b : visited)
      if (!b)
        return false;
    return true;
  }

  void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int v) {
    if (visited[v])
      return;
    visited[v] = true;
    for (int i : rooms[v]) {
      dfs(rooms, visited, i);
    }
  }
};
