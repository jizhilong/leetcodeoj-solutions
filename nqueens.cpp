/*
 * =====================================================================================
 *
 *       Filename:  nqueens.cpp
 *
 *    Description:  The n-queens puzzle is thr problem of placing n queens on an
 *                  nxn chessboard such that no two queens attack each other.
 *                  Given an integer n, return all distinct solutions to 
 *                  n-queens puzzle.
 *
 *        Version:  1.0
 *        Created:  03/23/2014 04:30:53 PM
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
#include <stdlib.h>

using namespace std;

class Solution {
  private:
    vector<vector<int> > _solveNQueens(int n) {
      vector<vector<int> > res;  /* res[i] is the queen's col index on the row i */
      if (1 == n) {
        res.push_back(vector<int>(1, 0));
        return res;
      }
      vector<vector<int> > tail = _solveNQueens(n-1);

      for (int i = 0; i < tail.size(); i++) {
        for (int j = 0; j < n; j++) {
          vector<int> prev = tail[i];
          for (int k = 0; k < n-1; k++) {
            if (prev[k] >= j) {
              prev[k]++;
            }
          }
          prev.push_back(j);
          res.push_back(prev);
        }
      }
      return res;
    }

  public:
    vector<vector<string> > solveNQueens(int n) {
      vector<vector<string> > res;
      vector<vector<int> > resi = _solveNQueens(n);

      for (int i = 0; i < resi.size(); i++) {
        bool fit = true;
        for (int j = 0; fit && j < n; j++) {
          for (int k = 0; k < j; k++) {
            if ((j - k) == abs(resi[i][j] - resi[i][k])) {
              fit = false;
              break;
            }
          }
        }

        if (fit) {
        res.push_back(vector<string>(n, string(n, '.')));
        for (int j = 0; j < n; j++) {
          res.back()[j][resi[i][j]] = 'Q';
          }
        }
      }

      return res;
    }
};

int
main(int argc, char *argv[])
{
  Solution solution;
  vector<vector<string> > res;
  int n = atoi(argv[1]);
  res = solution.solveNQueens(n);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < n; j++)
      cout << res[i][j] << endl;
    cout << endl;
  }
}
