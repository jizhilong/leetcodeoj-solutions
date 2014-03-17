/*
 * =====================================================================================
 *
 *       Filename:  interleaving_string.cpp
 *
 *    Description:  Given s1, s2, s3, find whether s3 is formed by interleaving of
 *                  s1 and s2.
 *                  For example.
 *                  Given:
 *                    s1 = "aabcc"
 *                    s2 = "dbbca"
 *                    when s3 = "aadbbcbcac", return true.
 *                    when s3 = "aadbbbaccc", return false.
 *
 *
 *        Version:  1.0
 *        Created:  03/16/2014 03:36:21 PM
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
#include <queue>
#include <assert.h>

using namespace std;

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
      int l1 = s1.length(), l2 = s2.length();
      if (l1 + l2 != s3.length())
        return false;
      vector<vector<bool> > dp(l1+1, vector<bool>(l2+1, false));
      dp[0][0] = true;  /* dp[i][j] means whether s1[0:i] and s2[0:j] can form s3[0:i+j] interleavely */
      queue<int> q;
      q.push(0); q.push(0);

      while (!q.empty()) {
        int i = q.front(); q.pop();
        int j = q.front(); q.pop();
        char c = s3[i+j];

        if (i < l1 && c == s1[i] && !dp[i+1][j]) {
          dp[i+1][j] = true;
          q.push(i+1);q.push(j);
        }
        if (j < l2 && c == s2[j] && !dp[i][j+1]) {
          dp[i][j+1] = true;
          q.push(i);q.push(j+1);
        }
      }

      return dp[l1][l2];
    }
};

int
main()
{
  Solution solution;


  string s4 = "bbaca";
  string s5 = "bbabaacbabaaaa";
  string s6 = "bbbabacaaabcbabaaaa";
  assert(!solution.isInterleave(s4, s5, s6));

  string s7 = "aabcc";
  string s8 = "dbbca";
  string s9 = "aadbbcbcac";
  assert(solution.isInterleave(s7, s8, s9));

  string sa = "cacccaa";
  string sb = "acccaacabbbab";
  string sc = "accccaaaccccabbaabab";
  assert(solution.isInterleave(sa, sb, sc));

  string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
  string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
  string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
  assert(!solution.isInterleave(s1, s2, s3));
}
