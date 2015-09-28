/*
 * =====================================================================================
 *
 *       Filename:  word_break2.cpp
 *
 *    Description:  Given a string s and a dictionary of words dict, add spaces in s
 *                  to construct a sentence where each word is a valid dictionary word.
 *                  Return all such possible sentences.
 *                  --------------------------------------------------------------------
 *                  s = "catsanddog"
 *                  dict = ["cat", "cats", "and", "sand", "dog"]
 *                  A solution is ["cats and dog", "cat sand dog"]
 *                  -------------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  02/24/2014 10:02:43 PM
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

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      int len = s.size();
      vector<vector<int> > dp(len+1, vector<int>());
      dp[len].push_back(len);

      for (int i = len - 1; i >= 0; i--)
        for (int j = i+1; j <= len; j++) {
          if (dict.find(s.substr(i, j-i)) != dict.end() && !dp[j].empty())
            dp[i].push_back(j);
        }


      vector<string> res;
      queue<int> q;
      queue<string> qs;
      q.push(0);
      qs.push("");

      while (!q.empty()) {
        int i = q.front(); q.pop();
        string str = qs.front(); qs.pop();

        for (vector<int>::iterator it = dp[i].begin(); it != dp[i].end(); it++) {
          int j = *it;
          string tmps = str + s.substr(i, j - i);
          if (j == len) {
            res.push_back(tmps);
          } else {
            tmps += " ";
            q.push(j);
            qs.push(tmps);
          }
        }
      }

      return res;
    }
};


int
main(int argc, char *argv[])
{
//  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
//  unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  string s = "catsanddog";
  unordered_set<string> dict = {"cat","cats","and","sand", "dog"};
  Solution solution;
  vector<string> res = solution.wordBreak(s, dict);

  for (vector<string>::iterator it = res.begin(); it != res.end(); it++)
    cout << *it << endl;
}
