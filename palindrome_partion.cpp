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
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<vector<string> > partition(string s) {
      vector<vector<bool> > dp(s.length(), vector<bool>(s.length(), false));

      for (int i = 0; i < s.length(); i++) {
        dp[i][i] = true;
        for (int j = i-1; j >= 0; j--) {
          if (s[j] == s[i] && (j+1 == i || j+2 == i || dp[j+1][i-1]))
            dp[j][i] = true;
        }
      }

      queue<int> q;
      queue<vector<string> > qs;
      vector<vector<string> > res;

      q.push(0);
      qs.push(vector<string>());

      while (!q.empty()) {
        int i = q.front(); q.pop();
        vector<string> vs = qs.front(); qs.pop();

        for (int j = i; j < dp[i].size(); j++) {
          if (dp[i][j]) {
            vector<string> vstmp = vs;
            vstmp.push_back(s.substr(i, j-i+1));
            if (j == dp[i].size() - 1) {
              res.push_back(vstmp);
            } else {
              q.push(j+1);
              qs.push(vstmp);
            }
          }
        }
      }

      return res;
    }
};


int
main(int argc, char *argv[])
{
  Solution solution;
  string s = "aabaa";
  vector<vector<string> > res = solution.partition(s);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
