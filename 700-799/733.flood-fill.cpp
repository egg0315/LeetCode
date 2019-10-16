/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    if (image[sr][sc] == newColor)
      return image;
    int oldColor = image[sr][sc];
    dfs(image, sr, sc, oldColor, newColor);
    return image;
  }

  void dfs(vector<vector<int>> &image, int i, int j, int oldColor,
           int newColor) {
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
        image[i][j] != oldColor)
      return;
    image[i][j] = newColor;
    dfs(image, i + 1, j, oldColor, newColor);
    dfs(image, i - 1, j, oldColor, newColor);
    dfs(image, i, j - 1, oldColor, newColor);
    dfs(image, i, j + 1, oldColor, newColor);
  }
};
