/*
 * =====================================================================================
 *
 *       Filename:  spiral_matrix2.cpp
 *
 *    Description:  Given an integer n, generate a square matrix filled with 
 *                  elements from 1 to n^2.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 08:57:30 AM
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
    vector<vector<int> > generateMatrix(int n) {
      vector<vector<int> >  matrix(n, vector<int>(n, 1));

      int i = 0, j = 0;
      int count = 1;
      while (true) {
        int nn = n - (i << 1);
        int di, dj;
        if (nn <= 0)
          break;

        matrix[i][j] = count++;
        for (dj = 1; dj < nn; dj++)
          matrix[i][j+dj] = count++;
        dj--;
        for (di = 1; di < nn; di++)
          matrix[i+di][j+dj] = count++;
        di--;
        if (nn > 1) {
          for (dj = dj - 1; dj > 0; dj--)
            matrix[i+di][j+dj] = count++;
          for (; di > 0; di--)
            matrix[i+di][j] = count++;
        }
        i++;j++;
      }
      return matrix;
    }
};

int
main()
{
  vector<vector<int> > res;
  Solution solution;
  res = solution.generateMatrix(1);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res.size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}
