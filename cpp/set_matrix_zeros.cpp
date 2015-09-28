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
      bool zero1strow = false;
      bool zero1stcol = false;

      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[0][j] == 0) {
          zero1strow = true;
          break;
        }
      }

      for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
          zero1stcol = true;
          break;
        }
      }

      for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
          if (matrix[i][j] == 0) {
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }

      for (int i = 1; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
          for (int j = 1; j < matrix[i].size(); j++)
            matrix[i][j] = 0;
        }
      }

      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[0][j] == 0) {
          for (int i = 1; i < matrix.size(); i++)
            matrix[i][j] = 0;
        }
      }

      if (zero1strow) {
        for (int j = 0; j < matrix[0].size(); j++)
          matrix[0][j] = 0;
      }

      if (zero1stcol) {
        for (int i = 0; i < matrix.size(); i++)
          matrix[i][0] = 0;
      }
    }
};

int
main()
{

}
