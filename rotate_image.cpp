/*
 * =====================================================================================
 *
 *       Filename:  rotate_image.cpp
 *
 *    Description:  You are given an n x n 2D matrix repersenting an image.
 *                  Rotate the image by 90 degrees(clockwise).
 *
 *        Version:  1.0
 *        Created:  03/21/2014 02:26:49 PM
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
    void rotate(vector<vector<int> > &matrix) {
      vector<vector<int> > back = matrix;
      int n = matrix.size();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          matrix[j][n-1-i] = back[i][j];
        }
      }
    }
};

int
main() {
  vector<vector<int> > matrix = {{1,2}, {1, 2}};
  Solution solution;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  solution.rotate(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}
