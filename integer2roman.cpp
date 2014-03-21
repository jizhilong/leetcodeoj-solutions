/*
 * =====================================================================================
 *
 *       Filename:  integer2roman.cpp
 *
 *    Description:  Given an integer, convert it to a roman numeral.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 10:06:24 AM
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
#include <assert.h>
#include <sstream>

using namespace std;

class Solution {
  public:
    string intToRoman(int num) {
      stringstream ss;
      while (num >= 1000) {
        ss << "M";
        num -= 1000;
      }

      switch (num / 100) {
        case 1:
          ss << "C";
          break;
        case 2:
          ss << "CC";
          break;
        case 3:
          ss << "CCC";
          break;
        case 4:
          ss << "CD";
          break;
        case 5:
          ss << "D";
          break;
        case 6:
          ss << "DC";
          break;
        case 7:
          ss << "DCC";
          break;
        case 8:
          ss << "DCCC";
          break;
        case 9:
          ss << "CM";
          break;
        default:
          break;
      }

      num = num % 100;
      switch (num / 10) {
        case 1:
          ss << "X";
          break;
        case 2:
          ss << "XX";
          break;
        case 3:
          ss << "XXX";
          break;
        case 4:
          ss << "XL";
          break;
        case 5:
          ss << "L";
          break;
        case 6:
          ss << "LX";
          break;
        case 7:
          ss << "LXX";
          break;
        case 8:
          ss << "LXXX";
          break;
        case 9:
          ss << "XC";
          break;
        default:
          break;
      }
      num = num % 10;
      switch (num) {
        case 1:
          ss << "I";
          break;
        case 2:
          ss << "II";
          break;
        case 3:
          ss << "III";
          break;
        case 4:
          ss << "IV";
          break;
        case 5:
          ss << "V";
          break;
        case 6:
          ss << "VI";
          break;
        case 7:
          ss << "VII";
          break;
        case 8:
          ss << "VIII";
          break;
        case 9:
          ss << "IX";
          break;
        default:
          break;
      }

      return ss.str();
    }
};


int
main()
{
  Solution solution;
  assert(solution.intToRoman(1437) == "MCDXXXVII");
  cout << solution.intToRoman(1437) << endl;
}
