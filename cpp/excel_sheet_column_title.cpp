/*
 * =====================================================================================
 *
 *       Filename:  excel_sheet_column_title.cpp
 *
 *    Description:  Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 *        Version:  1.0
 *        Created:  01/19/2015 09:07:25 PM
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
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
      stringstream s;
      while (n != 0) {
        if ( n % 26 == 0) {
          s << "Z";
          n= n/26 - 1;
        } else {
          s << (char)('@'+n%26);
          n = n/26;
        }
      }

      string result = s.str();
      reverse(result.begin(), result.end());
      return result;
    }
};

int
main(int argc, char *argv[])
{
  Solution s;
  cout << s.convertToTitle(1) << endl;
  cout << s.convertToTitle(26) << endl;
  cout << s.convertToTitle(27) << endl;
  cout << s.convertToTitle(28) << endl;
}
