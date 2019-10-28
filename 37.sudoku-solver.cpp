/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (39.28%)
 * Likes:    1165
 * Dislikes: 76
 * Total Accepted:    149.8K
 * Total Submissions: 380.9K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    // 11:01 -> 11:23
    void solveSudoku(vector<vector<char>> &board)
    {
        if (solve(board, 0))
            return;
    }

    bool solve(vector<vector<char>> &board, int index)
    {
        if (index == 81)
            return true;

        int i = index / 9, j = index % 9;
        if (board[i][j] != '.')
            return solve(board, index + 1);
        for (char c = '1'; c <= '9'; c++)
        {
            // check if c can be placed
            if (check(board, i, j, c))
            {
                board[i][j] = c;
                if (solve(board, index + 1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool check(vector<vector<char>> &board, int i, int j, char c)
    {
        // check row
        for (int k = 0; k < 9; k++)
        {
            if (board[i][k] == c || board[k][j] == c)
                return false;
        }
        int i0 = (i / 3) * 3, j0 = (j / 3) * 3;
        for (int p = 0; p < 3; p++)
        {
            for (int q = 0; q < 3; q++)
            {
                if (board[i0 + p][j0 + q] == c)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
