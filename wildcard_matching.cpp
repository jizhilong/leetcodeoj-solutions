/*
 * =====================================================================================
 *
 *       Filename:  wildcard_matching.cpp
 *
 *    Description:  Implement wildcard pattern matching with support for '?' and '*'.
 *
 *        Version:  1.0
 *        Created:  04/08/2014 07:52:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


class Solution {
  public:
    bool isMatch(const char *s, const char *p) {
	  int min = 0, max = 0;
	  int lens = strlen(s), lenp = strlen(p);
	  if (lens == 0 || lenp == 0) {
		while (*p == '*')
		  p++;
		return *s == *p;
	  }

	  for (int i = 0; i < lenp; i++) {
		if (min > lens)
		  return false;
		if (p[i] == '*') {
		  max = lens;
		} else if (p[i] == '?') {
		  min++;
		  if (max < min)
			max = min;
		} else {
		  while (min <= max && s[min] != p[i])
			min++;
		  if (s[min] == p[i])
			min++;
		  else
			return false;
		  while (max >= min && s[max] != p[i])
			max--;
		  if (s[max] == p[i])
			max++;
		  else
			return false;
		}
	  }

	  return max == lens;
    }
};


int
main()
{
  Solution solution;
  assert(!solution.isMatch("aa", "a"));
  assert(!solution.isMatch("ac", "*ab"));
  assert(solution.isMatch("aa", "aa"));
  assert(!solution.isMatch("aaa", "aa"));
  assert(solution.isMatch("aa", "*"));
  assert(solution.isMatch("aa", "a*"));
  assert(solution.isMatch("ab", "?*"));
  assert(!solution.isMatch("aab", "c*a*b"));
  assert(solution.isMatch("ho", "**ho"));
}
