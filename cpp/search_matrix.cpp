/*
 * =====================================================================================
 *
 *       Filename:  search_matrix.cpp
 *
 *    Description:  Write an efficient algorithm that searches for a value in an
 *                  m x n matrix.This matrix has the following properties.
 *                    Integers in each row are sorted from left to right.
 *                    The first integer of each row is greater than the last 
 *                    integer of the previous row.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 09:10:13 AM
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

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      if (matrix.empty())
        return false;
      int i;
      for (i = 0; i < matrix.size() && matrix[i].back() < target; i++);
      if (i == matrix.size() || matrix[i][0] > target)
        return false;
      int lo = 0, hi = matrix[i].size() - 1;
      while (lo <= hi) {
        int mid = (lo+hi)/2; 
        if (matrix[i][mid] == target) {
          return true;
        } else if (matrix[i][mid] < target) {
          lo = mid+1;
        } else {
          hi = mid-1;
        }
      }
      return false;
    }
};

int
main()
{
//  vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
  vector<vector<int> > matrix = {{1,2}};
  Solution solution;
  cout << solution.searchMatrix(matrix, 2) << endl;
}
