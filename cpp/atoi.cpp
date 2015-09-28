/*
 * =====================================================================================
 *
 *       Filename:  atoi.cpp
 *
 *    Description:  Implement atoi to convert a string to an integer.
 *
 *        Version:  1.0
 *        Created:  04/12/2014 02:56:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <ctype.h>
#include <limits.h>

using namespace std;

class Solution {
  public:
  int atoi(const char *s) {
    int res = 0;
    int sign = 1;
    while (isblank(*s)) s++;
    if (*s == '+' || *s == '-') {
      if (*s == '-')
        sign = -1;
      s++;
    }

    while (isdigit(*s)) {
      int tmp = res * 10;
      double dtmp = (double)res*10;

      if (dtmp != (double)tmp)
        goto return_overflow;

      int b = sign*(*s - '0');
      res = (int)((unsigned int)tmp+b);
      if ((res ^ tmp) < 0 && (res ^ b) < 0)
        goto return_overflow;
      s++;
    }

    return res;
return_overflow:
    return sign > 0 ? INT_MAX : INT_MIN;
  }
};

int
main()
{
  Solution *solution = new Solution();
  vector<const char *> strs = {"", "abc", "0", "1", "1ac", "1234", "1234a", 
                               "-1", "--1a", "012", "-012", "-12a", "  123",
                               "46738268", " 123 12", "+123", "2147483647", "-2147483648",
                               " 10522545459"};

  for_each(strs.begin(), strs.end(), 
           [solution](const char *s){ 
              assert(atoi(s) == solution->atoi(s));
            });
}


