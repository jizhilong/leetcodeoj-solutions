/*
 * =====================================================================================
 *
 *       Filename:  zig_zag_conversion.cpp
 *
 *    Description:  The string "PAYPALISHIRING" is written in a zigzag pattern
 *                  on a given number of rows like this:
 *                  P A H N
 *                  APLSIIG
 *                  Y I R
 *                  And then read line by line: "PAHNAPLSSIIGYIR" Write the code
 *                  that will take a string and make this conversion given a 
 *                  number of rows.
 *
 *        Version:  1.0
 *        Created:  03/27/2014 10:50:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    string convert(string s, int nRows) {
      int gap = max(1, 2*nRows - 2);
      stringstream ss;
      for (int i = 0; i < nRows; i++) {
        for (int j = i; j < s.length(); j += gap) {
           ss << s[j];
           if (i != 0 && i != nRows - 1 && j+gap-2*i < s.length())
             ss << s[j+gap-2*i];
        }
      }
      return ss.str();
    }
};

int
main()
{
  string s = "PAYPALISHIRING";
  Solution solution;
  cout << solution.convert(s, 1) << endl;
}
