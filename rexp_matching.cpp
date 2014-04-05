/*
 * =====================================================================================
 *
 *       Filename:  rexp_matching.cpp
 *
 *    Description:  Implement regular expression matching with support for '.' and '*'
 *
 *        Version:  1.0
 *        Created:  04/05/2014 12:51:40 PM
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
#include <string.h>
#include <stack>

using namespace std;

class Solution {
  public:
    bool isMatch(const char *s, const char *p) {
      int lens = strlen(s), lenp = strlen(p);
      if (lens == 0) {
        return lenp == 0;
      }
      if (lenp == 0) {
        return lens == 0;
      }

      stack<int> qs;
      stack<int> qp;
      qs.push(0);
      qp.push(0);
      char last;

      while (!qs.empty() && !qp.empty()) {
        int si = qs.top(); qs.pop();
        int pi = qp.top(); qp.pop();

        if (si == lens && pi == lenp) {
          return true;
        }

        switch (p[pi]) {
          case '*':
            if (si < lens && (s[si] == p[pi-1] || p[pi-1] == '.')) {
              qs.push(si+1);
              qp.push(pi);

              qs.push(si+1);
              qp.push(pi+1);
            }
            qs.push(si);
            qp.push(pi+1);
            break;
          case '.':
            if (si < lens) {
              qs.push(si+1);
              qp.push(pi+1);
            }
            break;
          default:
            if (si < lens && s[si] == p[pi]) {
              qs.push(si+1);
              qp.push(pi+1);
            } 
            if (pi+1 < lenp && p[pi+1] == '*') {
              qs.push(si);
              qp.push(pi+2);
            }
            break;
        }
      }

      return false;
    }
};

int
main()
{
  Solution solution;
  assert(!solution.isMatch("aa", "a"));
  assert(solution.isMatch("aa", "aa"));
  assert(!solution.isMatch("aaa", "a"));
  assert(solution.isMatch("aa", "a*"));
  assert(solution.isMatch("aa", ".*"));
  assert(solution.isMatch("ab", ".*"));
  assert(solution.isMatch("aab", "c*a*b"));
  assert(solution.isMatch("a", "ab*"));
  assert(solution.isMatch("aa", "a*c*a"));
  assert(solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b"));
}
