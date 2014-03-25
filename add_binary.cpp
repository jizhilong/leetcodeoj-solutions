/*
 * =====================================================================================
 *
 *       Filename:  add_binary.cpp
 *
 *    Description:  Given two binary strings, return their sum (also a binary
 *                  string).
 *
 *        Version:  1.0
 *        Created:  03/25/2014 10:08:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
      stringstream ss;
      int inc = 0;
      int i = a.length() - 1, j = b.length() - 1;

      while (i >= 0 || j >= 0) {
        if (i >= 0) {
          inc += a[i--] - '0';
        }
        if (j >= 0) {
          inc += b[j--] - '0';
        }
        ss << (char)('0'+(inc%2));
        inc /= 2;
      }

      if (inc)
        ss << "1";

      string res = ss.str();
      return string(res.rbegin(), res.rend());
    }
};


int
main()
{
  Solution solution;
  cout << solution.addBinary("11", "1") << endl;
}
