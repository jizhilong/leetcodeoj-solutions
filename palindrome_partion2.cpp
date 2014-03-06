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
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int minCut(string s) {
      vector<vector<bool> > dp(s.length(),vector<bool>(s.length(), false));

      for (int i = 0; i < s.length(); i++) {
        dp[i][i] = true;
        for (int j = i-1; j >= 0; j--) {
          if (s[j] == s[i] && (j+1 == i || j+2 == i || dp[j+1][i-1]))
            dp[j][i] = true;
        }
      }

      vector<int> dp2(s.length() + 1, s.length());
      dp2[s.length()] = -1;

      for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i; j < s.length(); j++) {
          if (dp[i][j] && dp2[i] > dp2[j+1]+1)
              dp2[i] = dp2[j+1]+1;
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
