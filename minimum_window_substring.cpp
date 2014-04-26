/*
 * =====================================================================================
 *
 *       Filename:  minimum_window_substring.cpp
 *
 *    Description:  Given a string S and a string T, find the minimum window in 
 *                  S which will contain all the characters in T in complexity
 *                  O(n).For example.
 *                  S = "ADOBECODEBANC".
 *                  T = "ABC"
 *                  Minumm windows is "BANC".
 *                  Note:
 *                  If there is no such window in S that cover all characters in
 *                  T, return the empty string "".If there are multiple such 
 *                  windows,you are guaranteed that there will always only one
 *                  unique minimum window in S.
 *
 *        Version:  1.0
 *        Created:  04/26/2014 10:45:18 AM
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
#include <utility>

using namespace std;


struct LN {
  int i;
  LN *next;
  LN *prev;

  LN(int index): i(index), next(NULL), prev(NULL) {}
};

typedef pair<int, LN*> Pair;

class Solution {
  public:
    string minWindow(string S, string T) {
      if (T.length() > S.length() || T.length() == 0)
        return "";
      vector<int>  chars(256, 0);
      vector<LN> dp(256, LN(0));

      LN match_head(0);
      LN *matche_tail = &match_head;
      int total = 0;

      for (int i = 0; i < T.length(); i++) {
        chars[T[i]]++;
      }

      int res_start = 0, res_len = S.length()+1;

      for (int i = 0; i < S.length(); i++) {
        char c = S[i];
        if (!chars[c])
          continue;

        if (dp[c].i < chars[c]) {
          total++;
          dp[c].i++;
        } else {
          LN *to_delete = dp[c].next->prev;

          to_delete->prev->next = to_delete->next;
          if (to_delete->next) {
            to_delete->next->prev = to_delete->prev;
          } else {
            matche_tail = to_delete->prev;
          }

          dp[c].next = dp[c].next->next;
        }

        matche_tail->next = new LN(i);
        matche_tail->next->prev = matche_tail;
        matche_tail = matche_tail->next;

        if (dp[c].next == NULL || dp[c].prev == NULL) {
          dp[c].next = dp[c].prev = new LN(i);
        } else {
          dp[c].prev->next = new LN(i);
          dp[c].prev = dp[c].prev->next;
        }
        dp[c].prev->prev = matche_tail;


        if (total == T.length()) {
          int tmplen = i - match_head.next->i + 1;
          if (tmplen < res_len) {
            res_start = match_head.next->i;
            res_len = tmplen;
          }
        }
      }

      return res_len <= S.length() ? S.substr(res_start, res_len) : "";
    }
};


int
main(int argc, char *argv[]) {
  string S = string(argv[1]);
  string T = string(argv[2]);
  Solution solution;
  cout << solution.minWindow(S, T) << endl;
}
