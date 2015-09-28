/*
 * =====================================================================================
 *
 *       Filename:  decode_ways.cpp
 *
 *    Description:  A message containing letters from A-Z is being encoded to
 *                  numbers using the following mapping:
 *                  ------------------------------------------------------------
 *                  'A' -> 1  'B' -> 2 ... 'Z' -> 26
 *                  ------------------------------------------------------------
 *                  Given an encoded message containing digits, determin the 
 *                  total number of ways to decode it.
 *                  For example, given encoded message "12", it could be decoded
 *                  as "AB" (1 2) or "L"(12).The number of ways decoding "12" is
 *                  2.
 *
 *
 *        Version:  1.0
 *        Created:  03/17/2014 08:22:41 PM
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
#include <string>

using namespace std;

class Solution {
  public:
    int numDecodings(string s) {
      if (s.length() == 0 || s[0] == '0')
        return 0;
      int dp1 = 1, dp2 = 0;
      for (int i = 1; i < s.length(); i++) {
        if (s[i] == '0' && (s[i-1] == '0' || s[i-1] > '2')) {
          return 0;
        } else if (s[i-1] == '0' || (10*(s[i-1] - '0') + s[i] - '0') > 26) {
          dp1 = dp1 + dp2;
          dp2 = 0;
        } else if (s[i] == '0'){
          dp2 = dp1;
          dp1 = 0;
        } else {
          int tmp = dp1;
          dp1 = dp1 + dp2;
          dp2 = tmp;
        } 
      }

      return dp1+dp2;
    }
};

int
main()
{
  string s = "122";
  Solution solution;
  assert(solution.numDecodings(s) == 3);
}
