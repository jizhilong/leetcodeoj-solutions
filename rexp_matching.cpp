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

#include <assert.h>

using namespace std;

class Solution {
  private:
    bool matchStar(char c, const char *s, const char *p) {
      const char *t;
      for (t = s; *t != '\0' && (*t == c || c == '.'); t++);
      do {
        if (isMatch(t, p))
          return true;
      } while (t-- > s);
      return false;
    }

  public:
    bool isMatch(const char *s, const char *p) {
      if (p[0] == '\0')
        return s[0] == '\0';
      if (p[1] == '*')
        return matchStar(p[0], s, p+2);
      if (p[1] == '+')
        return (s[0] == p[0] || p[0] == '.') && matchStar(p[0], s+1, p+2);
      if (p[0] == '$' && p[1] == '\0')
        return *s == '\0';
      if (s[0] != '\0' && (p[0] == '.' || p[0] == s[0]))
        return isMatch(s+1, p+1);
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
  assert(!solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c"));
  assert(solution.isMatch("", ".*"));
  assert(!solution.isMatch("", "b"));
  assert(solution.isMatch("bca", "b+a*c*a$"));
  assert(!solution.isMatch("ca", "b+a*c*a$"));
}
