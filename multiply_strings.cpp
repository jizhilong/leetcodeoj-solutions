/*
 * =====================================================================================
 *
 *       Filename:  multiply_strings.cpp
 *
 *    Description:  Given two numbers represented as strings, return multication
 *                  of the numbers as a string.Note: The numbers can be arbitrarily
 *                  large and are non-negative.
 *
 *        Version:  1.0
 *        Created:  04/04/2014 07:29:58 PM
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
#include <algorithm>

using namespace std;


class Solution {
  private:


    inline void shift(string &num, int n) {
      for (int i = 0; i < n; i++) {
        num.push_back('0');
      }
    }

    bool allzero(string str) {
      for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0')
          return false;
      }
      return true;
    }

  public:
    string add(string str1, string str2) {
      stringstream ss;
      int inc = 0;
      int e1 = str1.length()-1, e2 = str2.length()-1;
      while (e1 >= 0 || e2 >= 0) {
        if (e1 >= 0) {
          inc += str1[e1--] - '0';
        }

        if (e2 >= 0) {
          inc += str2[e2--] - '0';
        }
        ss << (inc % 10);
        inc /= 10;
      }
     if (inc)
       ss << inc;

     string ret = ss.str();
     reverse(ret.begin(), ret.end());
     return ret;
    }

    string sub(string str1, string str2) {
      stringstream ss;
      int e1 = str1.length()-1, e2 = str2.length()-1;
      int inc = 0;

      while (e2 >= 0) {
        inc -= str2[e2--]-'0';
        inc += str1[e1--]-'0';
        if (inc >= 0) {
          ss << inc;
          inc = 0;
        }
        else {
          ss << (inc+10);
          inc = -1;
        }
      }

      while (e1 >= 0) {
        inc += str1[e1--] - '0';
        if (inc >= 0) {
          ss << inc;
          inc = 0;
        }
        else {
          ss << (inc+10);
          inc = -1;
        }
      }

     string ret = ss.str();
     reverse(ret.begin(), ret.end());
     return ret;
    }

    string multiply(string num1, string num2) {
      int len1 = num1.length();
      int len2 = num2.length();

      if (len1 == 0 || len2 == 0 || allzero(num1) || allzero(num2)) 
        return "0";

      if (len1 < len2)
        return multiply(num2, num1);

      if (len1+len2 < 10) {
        int n1 = stoi(num1), n2 = stoi(num2);
        return to_string(n1*n2);
      }

      if (len2 == 1) {
        int n = num2[0]-'0';
        string ret = num1;
        for (int i = 1; i < n; i++) {
          ret = add(ret, num1);
        }
        return ret;
      }

      int rlen  = min(len1/2, len2/2);
      string x1 = num1.substr(0, len1-rlen);
      string x2 = num1.substr(len1-rlen);
      string y1 = num2.substr(0, len2-rlen);
      string y2 = num2.substr(len2-rlen);

      string A = multiply(x1, y1);
      string B = multiply(x2, y2);
      string C = multiply(add(x1,x2), add(y1,y2));
      string K = sub(C, add(A,B));
      shift(A, 2*rlen);
      shift(K, rlen);

      return add(A, add(B, K));
    }
};

int
main()
{
  Solution solution;
  cout << solution.multiply("1234567890", "1000000000") << endl;
}
