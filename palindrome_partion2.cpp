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

      queue<int> q;
      queue<int> qs;
      int last = s.length() - 1;

      q.push(0);
      qs.push(0);

      while (!q.empty()) {
        int i = q.front(); q.pop();
        int vs = qs.front(); qs.pop();

        for (unordered_set<int>::iterator it = dp[i].begin(); it != dp[i].end();it++) {
            if (*it == last) {
              return vs;
            } else {
              q.push(1+*it);
              qs.push(vs+1);
            }
        }
      }

      return -1;
    }
};


int
main(int argc, char *argv[])
{
  Solution solution;
  string s = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
  int res = solution.minCut(s);

  cout << res << endl;
  return 0;
}
