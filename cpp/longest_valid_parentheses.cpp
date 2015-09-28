/*
 * =====================================================================================
 *
 *       Filename:  longest_valid_parentheses.cpp
 *
 *    Description:  Given a string containing just the characters '(' and ')',
 *                  find the length of the longest valid parentheses substring.
 *                  For "(())", the longest valid parentheses substring is "()".
 *                  which has length = 2.
 *
 *        Version:  1.0
 *        Created:  04/07/2014 03:43:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <stack>
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
      stack<int> stk;
      vector<int> dp(s.length(), 0);
      int ret = 0;

      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
          stk.push(i);
        } else if (!stk.empty()) {
          dp[i] = i - stk.top() + 1;
          if (stk.top() > 0)
            dp[i] += dp[stk.top() - 1];
          if (dp[i] > ret)
            ret = dp[i];
          stk.pop();
        }
      }
      return ret;
    }
};

int
main()
{
  Solution solution;
  assert(solution.longestValidParentheses("(()") == 2);
  assert(solution.longestValidParentheses(")()())") == 4);
  assert(solution.longestValidParentheses("()()") == 4);
}
