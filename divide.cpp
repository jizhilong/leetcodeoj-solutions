/*
 * =====================================================================================
 *
 *       Filename:  divide.cpp
 *
 *    Description:  Divide two integers without using multiplication, division
 *                  and mod operator.
 *
 *        Version:  1.0
 *        Created:  04/12/2014 09:06:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
  private:

  public:
    inline bool abs_ge(int n, int m) { /* abs(n) >= abs(m) */
      int sign = n ^ m;
      if (sign < 0) {
        if (m == 0)
          return true;
        else if (m > 0)
          return n+m <= 0;
        else
          return n+m >= 0;
      } else if (sign > 0){
        if (m == 0)
          return true;
        else if (m > 0)
          return n-m >= 0;
        else
          return n-m <= 0;
      } else {
        return true;
      }
    }

    int divide(int dividend, int divisor) {
      if (dividend == 0)
        return 0;
      if (divisor == 1)
        return dividend;
      if (dividend == divisor)
        return 1;
      int sign = 1;
      if ((divisor ^ dividend) < 0)
        sign = -1;

      int ret = 0;
      while (abs_ge(dividend, divisor)) {
        int tmp = sign*divisor;
        int tret = sign;
        int tmpp = tmp + tmp;

        while ((tmpp^divisor^sign) > 0 && abs_ge(dividend, tmpp)) {
          tmp = tmpp;
          tret <<= 1;
          tmpp <<= 1;
        }
        ret += tret;
        dividend -= tmp;
      }

      return ret;
    }
};

  int
main()
{
  Solution solution;
  assert(!solution.abs_ge(0, -1));
  cout << solution.divide(-2147483648, 2) << endl;
  cout << solution.divide(1, -1) << endl;
}
