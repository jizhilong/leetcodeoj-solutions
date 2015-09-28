/*
 * =====================================================================================
 *
 *       Filename:  excel_sheet_column_number.cpp
 *
 *    Description:  Given a column title as appear in an Excel sheet, return its
 *                  corresponding column number.
 *
 *        Version:  1.0
 *        Created:  01/21/2015 10:13:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
  public:
    int titleToNumber(string s) {
      int base = 1;
      int res = 0;
      for (string::reverse_iterator it = s.rbegin(); it < s.rend(); it++) {
        res += (int)(*it - '@')*base;
        base *= 26;
      }
      return res;
    }
};


int
main(int argc, char *argv[]) {
  Solution s;
  cout << s.titleToNumber("A") << endl;
  cout << s.titleToNumber("B") << endl;
  cout << s.titleToNumber("AB") << endl;
}
