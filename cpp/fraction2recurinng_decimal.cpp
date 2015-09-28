/*
 * =====================================================================================
 *
 *       Filename:  fraction2recurinng_decimal.cpp
 *
 *    Description:  Given two integers representing the numerator and denominator, return
 *                  the fraction in string format. If the fractional part is repeating,
 *                  enclose the repeating part in parenthses.
 *                  For example,
 *                  Given numerator = 1, denominator = 2, return "0.5".
 *                  Given numerator = 2, denominator = 1, return "2".
 *                  Given numerator = 2, denominator = 3, return "0.(6)".
 *
 *        Version:  1.0
 *        Created:  01/27/2015 05:52:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;
#define abs(n) ((n)<0 ? -n : n)

class Solution {
  private:
    long gcd(long n, long d) {
      if (n < d) {
        return gcd(d, n);
      } else {
        while (d != 0) {
          long t = d;
          d = n % d;
          n = t;
        }
        return n;
      }
    }

    string _fractionToDecimal(long n, long d) {
      long g = gcd(n, d);
      n /= g;
      d /= g;
      long nn = n;
      set<long> mark;
      stringstream s;
      s << n / d;
      n = n % d;
      if (n == 0)
        return s.str();
      s << ".";
      while (n) {
        if (mark.find(n) != mark.end()) {
          break;
        }
        mark.insert(n);
        n *= 10;
        s << n / d;
        n = n % d;
      }
      if (n == 0)
        return s.str();
      stringstream ss;
      ss << nn / d << ".";
      nn = nn % d;
      while (nn != n) {
        nn *= 10;
        ss << nn / d;
        nn = nn % d;
      }
      ss << "(";
      do {
        nn *= 10;
        ss << nn / d;
        nn = nn % d;
      } while (nn != n);
      ss << ")";

      return ss.str();
    }
  public:
    string fractionToDecimal(int n, int d) {
      long nn = (long)n;
      long dd = (long)d;

      if (nn*dd < 0) {
        return "-"+_fractionToDecimal(abs(nn), abs(dd));
      }
        return _fractionToDecimal(abs(nn), abs(dd));
    }
};


int
main(int argc, char *argv[]) {
  Solution s;
  cout << s.fractionToDecimal(1, 2) << endl;
  cout << s.fractionToDecimal(2, 1) << endl;
  cout << s.fractionToDecimal(2, 3) << endl;
  cout << s.fractionToDecimal(2, 7) << endl;
  cout << s.fractionToDecimal(3, 14) << endl;
  cout << s.fractionToDecimal(3, -14) << endl;
  cout << s.fractionToDecimal(-1, -2147483648) << endl;
}
