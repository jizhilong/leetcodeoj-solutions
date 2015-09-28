/*
 * =====================================================================================
 *
 *       Filename:  roman2integer.cpp
 *
 *    Description:  Given a roman numeral, convert it to an integer.Input is 
 *                  guaranteed to be within the range from 1 to 3999.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 09:37:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
  private:
    int char2digit(char c) {
      switch (c) {
        case 'I':
          return 1;
        case 'V':
          return 5;
        case 'X':
          return 10;
        case 'L':
          return 50;
        case 'C':
          return 100;
        case 'D':
          return 500;
        case 'M':
          return 1000;
        default:
          return -1;
      }
    }

  public:
    int romanToInt(string s) {
      int res = 0;
      int pre = 0;
      for (int i = 0; i < s.length(); i++) {
        int cur = char2digit(s[i]);
        res += cur - (cur > pre ? 2*pre : 0);
        pre = cur;
      }
      return res;
    }
};

int
main()
{
  Solution solution;
  assert(solution.romanToInt("XLV") == 45);
  assert(solution.romanToInt("XCIX") == 99);
  assert(solution.romanToInt("VIII") == 8);
}
