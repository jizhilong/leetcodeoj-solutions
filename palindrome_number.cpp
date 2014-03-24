/*
 * =====================================================================================
 *
 *       Filename:  palindrome_number.cpp
 *
 *    Description:  Determine where an integer is a palindrome. Do thie without
 *                  extra space.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 10:24:01 AM
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
#include <cmath>

using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0)
        return false;
      int d = 1;
      while (x / d >= 10) {
        d = d*10;
      }

      while (d >= 10) {
        if ((x % 10) != x/d)
          return false;
        x = x % d;
        x = x / 10;
        d = d / 100;
      }
      return true;
    }
};

int
main()
{
  Solution solution;
  assert(solution.isPalindrome(11));
  assert(solution.isPalindrome(0));
  assert(!solution.isPalindrome(120));
  assert(!solution.isPalindrome(10));
  assert(!solution.isPalindrome(-120));
  assert(!solution.isPalindrome(12));
  assert(!solution.isPalindrome(-2147483648));
}
