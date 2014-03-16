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
#include <stack>
#include <assert.h>

using namespace std;

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
      if (s1.length() + s2.length() != s3.length())
        return false;
      stack<int> q1, q2;
      q1.push(0); q2.push(0);

      while (!q1.empty() && !q2.empty()) {
        int i1 = q1.top(), i2 = q2.top();
        int i = i1+i2;

        if (i1 == s1.length()) {
          for (; i2 < s2.length() && s2[i2] == s3[i1+i2]; i2++);
          if (i2 == s2.length())
            return true;
          q1.pop(); q2.pop();
       }
       else if (i2 == s2.length()) {
          for (; i1 < s1.length() && s1[i1] == s3[i1+i2]; i1++);
          if (i1 == s1.length())
            return true;
          q1.pop(); q2.pop();
       }
       else if (s1[i1] == s3[i]) {
         q1.pop(); q1.push(i1+1);
         if (s2[i2] == s3[i]) {
           q1.push(i1); q2.push(i2+1);
         } 
       } else if (s2[i2] == s3[i]) {
         q2.pop(); q2.push(i2+1);
       } else {
         q1.pop();
         q2.pop();
       }
      }

      return false;

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
