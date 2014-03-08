/*
 * =====================================================================================
 *
 *       Filename:  surrounded_redions.cpp
 *
 *    Description:  Given a 2D board containing 'X' and 'o', capture all regions
 *                  by 'X'. A region is captured by flipping all 'O's into 'X's
 *                  in that surrounded redion.
 *                  -----------------------------------------------------------
 *                  X X X X       X X X X
 *                  X o o X ===>  X X X X
 *                  X X o X ===>  X X X X
 *                  X O X X       X O X X
 *                  -----------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  03/08/2014 02:46:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> cell;

class Solution {
  public:
    void solve(vector<vector<char> > &board) {
      int height = board.size();
      if (height <= 1) {
        return;
      }
      int width = board[0].size();
      if (width <= 1) {
        return;
      }

      vector<vector<int> > record(height, vector<int>(width, -1));
      queue<cell> q;

      for (int i = 0; i < width;i++) {
        if (board[0][i] == 'O') {
          q.push(cell(0, i));
          record[0][i] = 1;
        } else {
          record[0][i] = 0;
        }

        if (board[height-1][i] == 'O') {
          q.push(cell(height-1, i));
          record[height-1][i] = 1;
        } else {
          record[height-1][i] = 0;
        }

      }

      for (int i = 0; i < height; i++) {
        if (board[i][width-1] == 'O') {
          q.push(cell(i, width-1));
          record[i][width-1] = 1;
        } else {
          record[i][width-1] = 0;
        }

        if (board[i][0] == 'O') {
          q.push(cell(i, 0));
          record[i][0] = 1;
        } else {
          record[i][0] = 0;
        }

      }

      while(!q.empty()) {
        cell c = q.front(); q.pop();
        int i = c.first, j = c.second;

        j--;
        if (j >= 0 && record[i][j] == -1) {
          if (board[i][j] == 'O') {
            q.push(cell(i, j));
            record[i][j] = 1;
          } else {
            record[i][j] = 0;
          }
        }

        j+=2;
        if (j < width && record[i][j] == -1) {
          if (board[i][j] == 'O') {
            q.push(cell(i, j));
            record[i][j] = 1;
          } else {
            record[i][j] = 0;
          }
        }

        i--,j--;
        if (i >= 0 && record[i][j] == -1) {
          if (board[i][j] == 'O') {
            q.push(cell(i, j));
            record[i][j] = 1;
          } else {
            record[i][j] = 0;
          }
        }
        
        i += 2;
        if (i < height && record[i][j] == -1) {
          if (board[i][j] == 'O') {
            q.push(cell(i, j));
            record[i][j] = 1;
          } else {
            record[i][j] = 0;
          }
        }
      }

      for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
          if (record[i][j] != 1)
            board[i][j] = 'X';
        }
    }
};

int
main()
{
  Solution solution;
  vector<vector<char> > board(4, vector<char>(6, 'X'));
  board[0][1] = board[0][3] = board[0][5] = 'O';
  board[1][0] = board[1][2] = board[1][4] = 'O';
  board[2][1] = board[2][3] = board[2][5] = 'O';
  board[3][0] = board[3][2] = board[3][4] = 'O';

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  solution.solve(board);
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

}
