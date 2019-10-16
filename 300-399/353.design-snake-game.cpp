/*
 * @lc app=leetcode id=353 lang=cpp
 *
 * [353] Design Snake Game
 *
 * https://leetcode.com/problems/design-snake-game/description/
 *
 * algorithms
 * Medium (31.49%)
 * Likes:    258
 * Dislikes: 97
 * Total Accepted:    23.9K
 * Total Submissions: 75.8K
 * Testcase Example:
 * '["SnakeGame","move","move","move","move","move","move"]\n[[3,2,[[1,2],[0,1]]],["R"],["D"],["R"],["U"],["L"],["U"]]'
 *
 * Design a Snake game that is played on a device with screen size = width x
 * height. Play the game online if you are not familiar with the game.
 *
 * The snake is initially positioned at the top left corner (0,0) with length =
 * 1 unit.
 *
 * You are given a list of food's positions in row-column order. When a snake
 * eats the food, its length and the game's score both increase by 1.
 *
 * Each food appears one by one on the screen. For example, the second food
 * will not appear until the first food was eaten by the snake.
 *
 * When a food does appear on the screen, it is guaranteed that it will not
 * appear on a block occupied by the snake.
 *
 * Example:
 *
 *
 * Given width = 3, height = 2, and food = [[1,2],[0,1]].
 *
 * Snake snake = new Snake(width, height, food);
 *
 * Initially the snake appears at position (0,0) and the food at (1,2).
 *
 * |S| | |
 * | | |F|
 *
 * snake.move("R"); -> Returns 0
 *
 * | |S| |
 * | | |F|
 *
 * snake.move("D"); -> Returns 0
 *
 * | | | |
 * | |S|F|
 *
 * snake.move("R"); -> Returns 1 (Snake eats the first food and right after
 * that, the second food appears at (0,1) )
 *
 * | |F| |
 * | |S|S|
 *
 * snake.move("U"); -> Returns 1
 *
 * | |F|S|
 * | | |S|
 *
 * snake.move("L"); -> Returns 2 (Snake eats the second food)
 *
 * | |S|S|
 * | | |S|
 *
 * snake.move("U"); -> Returns -1 (Game over because snake collides with
 * border)
 *
 *
 */
class SnakeGame {
public:
  /** Initialize your data structure here.
      @param width - screen width
      @param height - screen height
      @param food - A list of food positions
      E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the
     second is at [1,0]. */

  // definition : start (0,0), move right +1, move down +1
  // down(1, 0) up(-1, 0) right(0, 1), left(0, -1)
  unordered_map<string, pair<int, int>> dirs;

  SnakeGame(int width, int height, vector<vector<int>> &f) {
    index = 0;
    M = height;
    N = width;
    snake.push_back({0, 0});
    food = f;
    body.insert(0);
  }

  /** Moves the snake.
      @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
      @return The game's score after the move. Return -1 if game over.
      Game over when snake crosses the screen boundary or bites its body. */
  int move(string d) {
    int x = snake[0].first;
    int y = snake[0].second;
    if (d == "U")
      --x;
    else if (d == "L")
      --y;
    else if (d == "R")
      ++y;
    else if (d == "D")
      ++x;

    if (x < 0 || y < 0 || x >= M || y >= N)
      return -1;

    if (index < food.size() && x == food[index][0] && y == food[index][1]) {
      snake.insert(snake.begin(), {x, y});
      body.insert(x * N + y);
      ++index;
    } else {
      body.erase(snake.back().first * N + snake.back().second);
      snake.pop_back();
      if (body.count(x * N + y)) {
        return -1;
      }
      snake.insert(snake.begin(), {x, y});
      body.insert(x * N + y);
    }
    return snake.size() - 1;
  }

private:
  vector<pair<int, int>> snake;
  int M, N;
  int index;
  vector<vector<int>> food;
  unordered_set<int> body;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
