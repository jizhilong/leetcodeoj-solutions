/*
 * =====================================================================================
 *
 *       Filename:  reverse_polish.cpp
 *
 *    Description:   Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *                   Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *                   Some examples:
 *                   -------------------------------------------------------------
 *                   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *                   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *                   -------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  02/18/2014 08:40:43 PM
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
#include <stack>
#include <stdlib.h>

using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
      stack<int> stk;
      int i1, i2;
      for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
        if (isdigit((*it)[0]) || (*it).length() > 1) {
          stk.push(atoi((*it).c_str()));
          continue;
        }

        i1 = stk.top();
        stk.pop();
        i2 = stk.top();
        stk.pop();

        if ((*it).compare("+") == 0 ) {
          stk.push(i1 + i2);
        } else if ((*it).compare("-") == 0 ) { 
          stk.push(i2 - i1);
        } else if ((*it).compare("*") == 0 ) {
          stk.push(i1 * i2);
        } else if ((*it).compare("/") == 0 ) {
          stk.push(i2 / i1);
        }
      }
        return stk.top();
    }
};

int
main(int argc, char *argv[])
{
  vector<string> exps;
  Solution solution;
  exps.push_back("-1");
  exps.push_back("1");
  exps.push_back("*");
  exps.push_back("-1");
  exps.push_back("+");

  cout << solution.evalRPN(exps) << endl;
}
