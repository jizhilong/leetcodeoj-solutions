/*
 * =====================================================================================
 *
 *       Filename:  factorial_trailing_zeroes.cpp
 *
 *    Description:  Given an integer n, return the number of trailing zeroes in n!.
 *                  Your solution should be logarihmic time complexity.
 *
 *        Version:  1.0
 *        Created:  01/21/2015 10:06:11 PM
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
    int trailingZeroes(int n) {
      int res = 0;
      while (n) {
        res += n / 5;
        n /= 5;
      }
      return res;
    }
};

int
main(int argc, char *argv[])
{
  Solution s;
  cout << s.trailingZeroes(5) << endl;
  cout << s.trailingZeroes(10) << endl;
}
