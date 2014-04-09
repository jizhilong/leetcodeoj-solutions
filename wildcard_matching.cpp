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

	  vector<int> dp;
	  dp.push_back(0);

	  for (int i = 0; i < lenp; i++) {
		vector<int> tmp;
		if (dp.empty()) {
		  return false;
		}

		if (p[i] == '*') {
		  for (int j = dp[0]-1; j < lens; j++) {
			tmp.push_back(j+1);
		  }
		} else if (p[i] == '?') {
		  for (int j = 0; j < dp.size() && dp[j] < lens; j++) {
			tmp.push_back(dp[j]+1);
		  }
		} else {
		  for (int j = 0; j < dp.size() && dp[j] < lens; j++) {
			if (p[i] == s[dp[j]])
			  tmp.push_back(dp[j]+1);
		  }
		}
		dp.swap(tmp);
	  }

	  return !dp.empty() && dp.back() == lens;
    }
};


int
main()
{
  Solution solution;
//  assert(!solution.isMatch("aa", "a"));
//  assert(!solution.isMatch("ac", "*ab"));
//  assert(solution.isMatch("aa", "aa"));
  assert(!solution.isMatch("aba", "*aa"));
  assert(!solution.isMatch("aaa", "aa"));
  assert(solution.isMatch("aa", "*"));
  assert(solution.isMatch("aa", "a*"));
  assert(solution.isMatch("ab", "?*"));
  assert(!solution.isMatch("aab", "c*a*b"));
  assert(solution.isMatch("ho", "**ho"));
}
