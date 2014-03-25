/*
 * =====================================================================================
 *
 *       Filename:  pow.cpp
 *
 *    Description:  Implement pow(x, n)
 *
 *        Version:  1.0
 *        Created:  03/25/2014 09:30:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution {
  public:
    double pow(double x, int n) {
      if (0 == n)
        return 1.0;

      int nn = n / 2;
      if (0 > nn)
        nn = -nn;

      double res = pow(x, nn);
      if (n % 2 == 0)
        res = res*res;
      else
        res = res*res*x;
      return n > 0 ? res : 1.0/res;
    }
};


int
main()
{
  double x = 3.0;
  int y = -2147483648;
  Solution solution;
  cout << solution.pow(x,-2) << endl;
  cout << solution.pow(x,-3) << endl;
  cout << solution.pow(x,-1) << endl;
  cout << solution.pow(1.0,y) << endl;
}
