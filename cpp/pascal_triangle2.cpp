/*
 * =====================================================================================
 *
 *       Filename:  pascal_triangle2.cpp
 *
 *    Description:  given an index k, return the kth row of the pascal's triangle
 *
 *        Version:  1.0
 *        Created:  03/13/2014 09:12:05 PM
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
    vector<int> getRow(int rowIndex) {
      vector<int> up(rowIndex + 1, 1);
      vector<int> res(rowIndex + 1, 1);

      for (int i = 1; i <= rowIndex; i++) {
        for (int j = 1; j < i; j++) {
          res[j] = up[j-1] + up[j];
        }
        up = res;
      }

      return res;
    }
};

int
main(int argc, char *argv[]) {
  Solution solution;
  vector<int> result = solution.getRow(3);

  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  cout << endl;
}
