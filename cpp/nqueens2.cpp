/*
 * =====================================================================================
 *
 *       Filename:  nqueens2.cpp
 *
 *    Description:  Follow up for N-Queens problem.Now, instead outputting
 *                  board configurations, return the total number of 
 *                  distinct solutions.
 *
 *        Version:  1.0
 *        Created:  03/23/2014 08:28:23 PM
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
  public:
    int totalNQueens(int n) {
      int res = 0;
      queue<vector<int> > q;
      q.push(vector<int>());
      queue<int> maskdls, maskdrs, masks;
      maskdls.push(0); maskdrs.push(0); masks.push(0);

      while (!q.empty()) {
        vector<int> candidate = q.front(); q.pop();
        int maskdl = maskdls.front(); maskdls.pop();
        int maskdr = maskdrs.front(); maskdrs.pop();
        int mask = masks.front(); masks.pop();
        int len = candidate.size();

        for (int j = 0; j < n; j++) {
          int m = 1 << j;
          int mdl = 1 << (len + j);
          int mdr = 1 << (n-1-j+len);
          if (((mask | m)^ mask) && ((maskdl | mdl) ^ maskdl) && ((maskdr | mdr) ^ maskdr)) {
            vector<int> newcandidate = candidate;
            newcandidate.push_back(j);
            if (len < n-1) {
              q.push(newcandidate);
              masks.push(mask | m);
              maskdls.push(maskdl | mdl);
              maskdrs.push(maskdr | mdr);
            } else {
              res++;
            }
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
  int res;
  int n = atoi(argv[1]);
  res = solution.totalNQueens(n);
  cout << res << endl;
}
