/*
 * =====================================================================================
 *
 *       Filename:  spiral_matrix.cpp
 *
 *    Description:  Given a matrix of m x n elements (m rows, n columns), return
 *                  all elements of the matrix in spiral order.For example,Given
 *                  the following matrix:
 *                          1,2,3
 *                          4,5,6
 *                          7,8,9
 *                  You should return [1,2,3,6,9,8,7,4,5]
 *
 *        Version:  1.0
 *        Created:  03/24/2014 08:12:16 AM
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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int> res;
      int m = matrix.size();
      if (m == 0)
        return res;
      int n = matrix[0].size();

      int i = 0, j = 0;
      while (true) {
        int mm = m - (i<<1), nn = n - (j<<1);
        int di, dj;
        if (mm <= 0 || nn <= 0)
          break;

        res.push_back(matrix[i][j]);
        for (dj = 1; dj < nn; dj++)
          res.push_back(matrix[i][j+dj]);
        dj--;
        for (di = 1; di < mm; di++)
          res.push_back(matrix[i+di][j+dj]);
        di--;
        if (mm > 1) {
          for (dj = dj - 1; dj > 0; dj--)
            res.push_back(matrix[i+di][j+dj]);
        }
        if (nn > 1) {
          for (; di > 0; di--)
            res.push_back(matrix[i+di][j]);
        }
        i++;j++;
      }
      return res;
    }
};

int
main()
{
  vector<vector<int> > matrix = {{1}};
  vector<int> res;
  Solution solution;
  res = solution.spiralOrder(matrix);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}
