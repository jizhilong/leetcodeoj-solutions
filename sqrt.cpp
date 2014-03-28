/*
 * =====================================================================================
 *
 *       Filename:  sqrt.cpp
 *
 *    Description:  Implement int sqrt(int x)
 *
 *        Version:  1.0
 *        Created:  03/29/2014 12:11:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
  private:
    double sqrt(double x) {
      double res = 1.0;
      while (abs(res*res-x) > 0.000001) {
        res = (res+x/res)/2;
      }
      return res;
    }

  public:
    int sqrt(int x) {
      return (int)sqrt((double)x);
    }
};

int
main() {
  Solution solution;
  cout << solution.sqrt(9) << endl;
}
