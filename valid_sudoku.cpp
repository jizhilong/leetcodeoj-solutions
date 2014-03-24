/*
 * =====================================================================================
 *
 *       Filename:  valud_sudoku.cpp
 *
 *    Description:  Determine if a Sudoku is valid, The Sudoku board could be 
 *                  partially filled, where empty cells are filled with character '.'
 *
 *        Version:  1.0
 *        Created:  03/24/2014 03:50:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char> > &board) {
      vector<vector<bool> > rows(9, vector<bool>(9, false));
      vector<vector<bool> > cols(9, vector<bool>(9, false));
      vector<vector<bool> > blocks(9, vector<bool>(9, false));

      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          if (board[i][j] == '.')
            continue;
          int d = board[i][j] - '0' - 1;
          if (rows[i][d]) {
            return false;
          } else {
            rows[i][d] = true;
          }

          if (cols[j][d]) {
            return false;
          } else {
            cols[j][d] = true;
          }

          if (blocks[3*(i/3) + j / 3][d]) {
            return false;
          } else {
            blocks[3*(i/3) + j/3][d] = true;
          }
        }
      }
      return true;
    }
};

int
main()
{
}

