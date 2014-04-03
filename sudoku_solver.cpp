/*
 * =====================================================================================
 *
 *       Filename:  sudoku_solver.cpp
 *
 *    Description:  Write a program to solve a Sudoku puzzle by filling the empty
 *                  cells.Empty cells are indicated by the character '.'.
 *                  You may assume that there will be only one unique solution,
 *
 *        Version:  1.0
 *        Created:  03/29/2014 10:04:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
  private:
    vector<vector<bool> > rows;
    vector<vector<bool> > cols;
    vector<vector<bool> > blocks;
    vector<pair<int, int> > holes;

    bool solveSudoku(vector<string> &board, int h) {
      if (h >= holes.size())
        return true;
      int i = holes[h].first, j = holes[h].second;
      int b = 3*(i/3) + j/3;

      for (int k = 0; k < 9; k++) {
        if (!(rows[i][k] || cols[j][k] || blocks[b][k])) {
          rows[i][k] = true;
          cols[j][k] = true;
          blocks[b][k] = true;
          board[i][j] = k + '0' + 1;
          if (solveSudoku(board, h+1))
            return true;
          rows[i][k] = false;
          cols[j][k] = false;
          blocks[b][k] = false;
        }
      }

      return false;
    }

  public:
    void solveSudoku(vector<string> &board) {
      rows = vector<vector<bool> >(9, vector<bool>(9, false));
      cols = vector<vector<bool> >(9, vector<bool>(9, false));
      blocks = vector<vector<bool> >(9, vector<bool>(9, false));

      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          if (board[i][j] == '.') {
            holes.push_back(pair<int,int>(i,j));
            continue;
          }
          int d = board[i][j] - '0' - 1;
          rows[i][d] = true;
          cols[j][d] = true;
          blocks[3*(i/3) + j/3][d] = true;
        }
      }

      solveSudoku(board, 0);
    }
};

int
main()
{
  vector<string> board = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
  Solution solution;
  for (int i = 0; i < board.size(); i++)
    cout << board[i] << endl;
  solution.solveSudoku(board);
  for (int i = 0; i < board.size(); i++)
    cout << board[i] << endl;
}
