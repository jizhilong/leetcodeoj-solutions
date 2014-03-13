/*
 * =====================================================================================
 *
 *       Filename:  pascal_triangle.cpp
 *
 *    Description:  given numRows, generate the first numRows of Pascal' triangle
 *
 *        Version:  1.0
 *        Created:  03/13/2014 08:56:38 PM
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
    vector<vector<int> > generate(int numRows) {
      vector<vector<int> > res;
      if (numRows == 0)
        return res;
      res.push_back(vector<int>(1, 1));

      for (int i = 1; i < numRows; i++) {
        res.push_back(vector<int>(i+1, 0));
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++) {
          res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
      }

      return res;
    }
};

int
main(int argc, char *argv[]) {
  Solution solution;
  vector<vector<int> > res = solution.generate(5);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) 
      cout << res[i][j] << " ";
    cout << endl;
  }

  return 0;
}
