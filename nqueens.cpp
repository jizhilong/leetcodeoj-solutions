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
#include <queue>
#include <stdlib.h>

using namespace std;

class Solution {
  private:
    vector<vector<int> > _solveNQueens(int n) {
      vector<vector<int> > res;  /* res[i] is the queen's col index on the row i */
      queue<vector<int> > q;
      q.push(vector<int>());
      queue<int> maskls, maskrs, masks;
      maskls.push(0); maskrs.push(0); masks.push(0);

      while (!q.empty()) {
        vector<int> candidate = q.front(); q.pop();
        int maskl = maskls.front(); maskls.pop();
        int maskr = maskrs.front(); maskrs.pop();
        int mask = masks.front(); masks.pop();
        int len = candidate.size();

        for (int j = 0; j < n; j++) {
          int m = 1 << j;
          int mm = mask | maskl | maskr;
          if (mm ^ (mm | m)) {
            vector<int> newcandidate = candidate;
            newcandidate.push_back(j);
            if (len < n-1) {
              q.push(newcandidate);
              masks.push(mask | m);
              maskls.push(maskl >> 1 | (j > 0 ? 1 << (j-1) : 0));
              maskrs.push(maskr << 1 | (j < n-1 ? 1 << (j+1) : 0));
            } else {
              res.push_back(newcandidate);
            }
          }
        }
      }

      return res;
    }

  public:
    vector<vector<string> > solveNQueens(int n) {
      vector<vector<string> > res;
      vector<vector<int> > resi = _solveNQueens(n);

      for (int i = 0; i < resi.size(); i++) {
        res.push_back(vector<string>(n, string(n, '.')));
        for (int j = 0; j < n; j++) {
          res.back()[j][resi[i][j]] = 'Q';
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
