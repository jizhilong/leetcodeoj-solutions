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
#include <iostream>
#include <cstring>

using namespace std;


class Solution {
  public:
    bool isMatch(const char *s, const char *p) {
      int lens = strlen(s);
	  vector<char> pp;
	  int rightmost = lens;
	  for (p; *p != '\0'; p++) {
		if (*p == '*') {
		  if (pp.empty() || pp.back() != '*')
			pp.push_back('*');
		} else {
		  pp.push_back(*p);
          rightmost--;
		}
	  }

	  int lenp = pp.size();
	  if (lens == 0)
		return rightmost == 0;
	  if (rightmost < 0)
		return false;

	  vector<int> dp;
	  dp.push_back(0);

	  for (int i = 0; i < lenp; i++) {
		if (dp.empty()) {
		  return false;
		}

		vector<int> tmp;

		if (pp[i] == '*') {
		  for (int j = dp[0]; j <= rightmost; j++) {
			tmp.push_back(j);
		  }
		} else {
		  for (int j = 0; j < dp.size() && dp[j] <= rightmost; j++) {
			if (pp[i] == '?' || pp[i] == s[dp[j]])
			  tmp.push_back(dp[j]+1);
		  }
          rightmost++;
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
