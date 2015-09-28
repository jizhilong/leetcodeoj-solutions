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
      int bsign = n ^ (-m);
      if (sign == 0 || bsign == 0)
        return true;

      return sign < 0 ? ((n+m)^m) < 0 : ((n-m)^m) >= 0;
    }

    int divide(int dividend, int divisor) {
      if (dividend == 0)
        return 0;
      if (divisor == 1)
        return dividend;
      if (dividend == divisor)
        return 1;
      if ((dividend+divisor) == 0)
        return -1;

      int sign = ((divisor ^ dividend) < 0) ? -1 : 1;

      int ret = 0;
      int bdivisor = sign*divisor;
      while (abs_ge(dividend, divisor)) {
        int tmp = bdivisor;
        int tret = sign;
        int tmpp = tmp + tmp;

        while ((tmpp^bdivisor) > 0 && abs_ge(dividend, tmpp)) {
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
  cout << solution.divide(-2147483648, -2147483648) << endl;
  cout << solution.divide(1, -1) << endl;
}
