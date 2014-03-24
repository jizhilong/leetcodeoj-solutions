/*
 * =====================================================================================
 *
 *       Filename:  valid_parentheses.cpp
 *
 *    Description:  Given a string containing just the characters '(',')','[',']'
 *                  determin if the input string is valid.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 03:16:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <stack>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
  public:
    bool isValid(string str) {
      stack<char> s;
      for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
          case '(':
          case '[':
          case '{':
            s.push(str[i]);
            break;
          case ')':
            if (s.empty() || s.top() != '(')
              return false;
            s.pop();
            break;
          case ']':
            if (s.empty() || s.top() != '[')
              return false;
            s.pop();
            break;
          case '}':
            if (s.empty() || s.top() != '{')
              return false;
            s.pop();
            break;
        }
      }
      return s.empty();
    }
};

int
main()
{
  Solution solution;
  assert(solution.isValid("()"));
  assert(!solution.isValid("(["));
  assert(!solution.isValid("([)]"));
}
