/*
 * =====================================================================================
 *
 *       Filename:  set_matrix_zeros.cpp
 *
 *    Description:  Given a m x n matrix, if an element is 0, set its entire row
 *                  and column to 0.Do it in place.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 06:48:02 AM
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
    void setZeroes(vector<vector<int> > &matrix) {
      if (matrix.empty())
        return;
      vector<bool> rows(matrix.size(), false);
      vector<bool> cols(matrix[0].size(), false);

      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
          if (matrix[i][j] == 0) {
            rows[i] = true;
            cols[j] = true;
          }
        }
      }

      for (int i = 0; i < matrix.size(); i++) {
        if (rows[i]) {
          for (int j = 0; j < matrix[i].size(); j++)
            matrix[i][j] = 0;
        }
      }

      for (int j = 0; j < matrix[0].size(); j++) {
        if (cols[j]) {
          for (int i = 0; i < matrix.size(); i++)
            matrix[i][j] = 0;
        }
      }
    }
};

int
main()
{

}
