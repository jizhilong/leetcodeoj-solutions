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
      vector<vector<int> > dp(2, vector<int>(n+1, 0));
      int up = 0, cur = 1;


      for (int j = 0; j <= n; j++) { /* how many steps required to convert "" to word2.substr(0,j) */
        dp[up][j] = j;
      }

      for (int i = 1; i <= m; i++) { /* how many steps required to convert word1.substr(0,i) to word2.substr(0,j) */
        dp[cur][0] = i;             
        for (int j = 1; j <= n; j++) {
          if (word1[i-1] == word2[j-1]) {
            dp[cur][j] = dp[up][j-1];
          } else {
            dp[cur][j] = 1+ min(dp[up][j], /* delete */
                           min(dp[cur][j-1], /* insert */
                               dp[up][j-1]) /* replace*/
                          );
          }
        }
        swap(cur, up);
      }


      return dp[up].back();
    }
};


int
main()
{
  string a = "ba";
  string b = "ac";
  Solution solution;
  cout << solution.minDistance(a, b) << endl;

}
