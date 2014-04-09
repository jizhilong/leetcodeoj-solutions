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
	  vector<char> pp;
	  int nonstarts = 0;
	  for (p; *p != '\0'; p++) {
		if (*p == '*') {
		  if (pp.empty() || pp.back() != '*')
			pp.push_back('*');
		} else {
		  pp.push_back(*p);
		  nonstarts++;
		}
	  }

	  int lens = strlen(s), lenp = pp.size();
	  if (lens == 0)
		return nonstarts == 0;
	  if (nonstarts > lens)
		return false;

	  vector<int> dp;
	  dp.push_back(0);

	  for (int i = 0; i < lenp; i++) {
		vector<int> tmp;
		if (dp.empty()) {
		  return false;
		}

		if (pp[i] == '*') {
		  for (int j = dp[0]; j <= lens - nonstarts; j++) {
			tmp.push_back(j);
		  }
		} else if (pp[i] == '?') {
		  nonstarts--;
		  for (int j = 0; j < dp.size() && dp[j]+1 <= lens - nonstarts; j++) {
			tmp.push_back(dp[j]+1);
		  }
		} else {
		  nonstarts--;
		  for (int j = 0; j < dp.size() && dp[j]+1 <= lens - nonstarts; j++) {
			if (pp[i] == s[dp[j]])
			  tmp.push_back(dp[j]+1);
		  }
		}
		dp.swap(tmp);
	  }

	  return !dp.empty() && dp.back() == lens;
    }
};


int
main(int argc, char *argv[])
{
  Solution solution;
  if (argc >= 3)
	cout << solution.isMatch(argv[1], argv[2]) << endl;
  assert(!solution.isMatch("aa", "a"));
  assert(!solution.isMatch("ac", "*ab"));
  assert(solution.isMatch("aa", "aa"));
  assert(!solution.isMatch("aba", "*aa"));
  assert(!solution.isMatch("aaa", "aa"));
  assert(solution.isMatch("aa", "*"));
  assert(solution.isMatch("aa", "a*"));
  assert(solution.isMatch("ab", "?*"));
  assert(!solution.isMatch("aab", "c*a*b"));
  assert(solution.isMatch("ho", "**ho"));
}
