/*
 * =====================================================================================
 *
 *       Filename:  distinct_subsqquecnces.cpp
 *
 *    Description:  Given a string S and a string T, count the number of distin
 *                  ct subsequences of T in S. 
 *                  -----------------------------------------------------------
 *                  example
 *                    S = "rabbbit", T = "rabbit" 
 *                    returns 3.
 *                  ------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  03/14/2014 12:46:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int numDistinct(string S, string T) {
      vector<vector<int> > dp(2, vector<int>(T.size(), 0));

      for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        int prev = i % 2;
        int cur = 1 - prev;
        for (int j = 0; j < T.size(); j++) {
          if (c == T[j]) {
            dp[cur][j] = dp[prev][j] + (j > 0 ? dp[prev][j-1] : 1);
          } else {
            dp[cur][j] = dp[prev][j];
          }
        }
      }

      return max(dp[0].back(), dp[1].back());
    }
};

int
main(int argc, char *argv[]) {
  Solution solution;
  string S = "rabbbit";
  string T = "rabbit";

  cout << solution.numDistinct(S, T) << endl;
  return 0;
}
