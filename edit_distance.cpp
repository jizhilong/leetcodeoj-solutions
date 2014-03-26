/*
 * =====================================================================================
 *
 *       Filename:  edit_distance.cpp
 *
 *    Description:  Given two words word1 and word2, find the minimum number of
 *                  steps required to convert word1 to word2. (each operation
 *                  is counted as 1 step.)
 *                  You have the following 3 operations permitted on a word:
 *                  a) insert a character
 *                  b) delete a character
 *                  c) replace a character
 *
 *        Version:  1.0
 *        Created:  03/26/2014 10:02:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
      int m = word1.length();
      int n = word2.length();
      if (m == 0 || n ==0)
        return m+n;
      vector<vector<int> > dp(m, vector<int>(n, 0));

      dp[0][0] = word1[0] == word2[0] ? 0 : 1;
      for (int i = 1; i < m; i++) { /* how many steps required to convert word1[0:i+1] to word2[0:1] */
        dp[i][0] = word1[i] == word2[0] ? i : dp[i-1][0] + 1;
      }

      for (int j = 1; j < n; j++) { /* how many steps required to convert word1[0:1] to word2[0:j+1]*/
        dp[0][j] = word2[j] == word1[0] ? j : dp[0][j-1] + 1;

      }

      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) { /* how many steps required to convert word1[0:i+1] to word2[0:j+1] */
          if (word1[i] == word2[j]) {
            dp[i][j] = dp[i-1][j-1];
          } else {
            dp[i][j] = 1+ min(dp[i-1][j], /* delete the ith character */
                           min(dp[i][j-1], /* insert a character after the ith one.*/
                               dp[i-1][j-1]) /* replace word1[i] with word2[j] */
                          );
          }
        }
      }

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
          cout << dp[i][j] << " ";
        cout << endl;
      }

      return dp.back().back();
    }
};


int
main()
{
  string a = "ab";
  string b = "bc";
  Solution solution;
  cout << solution.minDistance(a, b) << endl;

}
