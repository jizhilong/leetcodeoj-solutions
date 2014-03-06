/*
 * =====================================================================================
 *
 *       Filename:  palindrome_partion.cpp
 *
 *    Description:  Given a string s, partition s such that every substring of
 *                  the partition is a palindrome.Return all possible palindrome
 *                  partition of s.
 *                  -----------------------------------------------------------
 *                  s = "aab" ===> [["aa", "b"], ["a", "a", "b"]]
 *                  -----------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  03/05/2014 03:43:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int minCut(string s) {
      vector<unordered_set<int> > dp(s.length(), unordered_set<int>());

      for (int i = 0; i < s.length(); i++) {
        dp[i].insert(i);
        for (int j = i-1; j >= 0; j--) {
          if (s[j] == s[i] && (j+1 == i || j+2 == i || dp[j+1].find(i-1) != dp[j+1].end()))
            dp[j].insert(i);
        }
      }

      vector<int> dp2(s.length() + 1, s.length());
      dp2[s.length()] = -1;

      for (int i = s.length() - 1; i >= 0; i--) {
        for (unordered_set<int>::iterator it = dp[i].begin(); it != dp[i].end(); it++) {
          if (dp2[i] > dp2[1+*it]+1)
            dp2[i] = dp2[1+*it]+1;
        }
      }

      return dp2[0];
    }
};


int
main(int argc, char *argv[])
{
  Solution solution;
  string s = argv[1];
  int res = solution.minCut(s);

  cout << res << endl;
  return 0;
}
