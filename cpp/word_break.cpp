/*
 * =====================================================================================
 *
 *       Filename:  word_break.cpp
 *
 *    Description:  Given a string s and a dictionary of words dict, determin if s can be
 *                  segmented into a space-separated sequence of one or more dictionary 
 *                  words.
 *                  --------------------------------------------------------------------
 *                  given s = "leetcode", dict = ["leet", "code"]
 *                  return true because "leetcode" can be segmented as "leetcode".
 *                  -------------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  02/24/2014 04:27:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmial.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
  public:

    bool wordBreak(string s, unordered_set<string> &dict) {
      int len = s.size();

      vector<bool> dp(len+1, false);
      dp[len] = true;

      for (int i = len - 1; i >= 0; i--) {
        for (int j = i+1; j <= len; j++) {
          if (dict.find(s.substr(i, j-i)) != dict.end() && dp[j]) {
              dp[i] = true;
              break;
          }
        }
      }

      return dp[0];
    }
};


int
main(int argc, char *argv[])
{
//  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
//  unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  string s = "leetcode";
  unordered_set<string> dict = {"leet","code","bbbb"};
  Solution solution;
  cout << solution.wordBreak(s, dict) << endl;
}
