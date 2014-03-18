/*
 * =====================================================================================
 *
 *       Filename:  scramble_string.cpp
 *
 *    Description:  Given a string s1, we may represent it as a binary tree by
 *                  partition it to two non-empty substrings recursively.
 *                  Below is one possible representation of s1 = "great":
 *                  -----------------------------------------------------------
 *                                       great
 *                                       /    \
 *                                      gr    eat
 *                                     / \    /  \
 *                                    g   r  e   at
 *                                               / \
 *                                              a   t 
 *                  ------------------------------------------------------------
 *                  To scramble the string, we may choose any non-leaf node and
 *                  swap its two children.For example, if we choose the node 
 *                  "gr" and swap its two children, it produces a scramble 
 *                  string "rgeat".We say that "rget" is a scrambled string of 
 *                  "great".Similarly, if we continue to swap the children of 
 *                  nodes "eat" and "at", it produces a scramble string "rgtae"
 *                  
 *                  Given two string s1 and s2 of the same length, determin if 
 *                  s2 is a scrambled string of s1.
 *
 *        Version:  1.0
 *        Created:  03/17/2014 09:06:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
  private:
    string s1, s2;

    bool _isScramble(string s1, string s2) {
      int len = s1.length();
      if (s1 == s2)
        return true;

      string tmp1 = s1, tmp2 = s2;
      sort(tmp1.begin(), tmp1.end());
      sort(tmp2.begin(), tmp2.end());
      if (tmp1 != tmp2)
        return false;

      for (int i = 1; i < len; i++) {
        string l1 = s1.substr(0, i);
        string r1 = s1.substr(i);
        string l2 = s2.substr(0, i);
        string r2 = s2.substr(i);

        if (_isScramble(l1, l2) && _isScramble(r1, r2))
          return true;

        l2 = s2.substr(len-i);
        r2 = s2.substr(0, len-i);

        if (_isScramble(l1, l2) && _isScramble(r1, r2))
          return true;
      }

      return false;
    }

  public:
    bool isScramble(string s1, string s2) {
      if (s1.length() != s2.length())
        return false;
      return _isScramble(s1, s2);
    }
};

int
main()
{
  Solution solution;
  string s1 = "great";
  string s2 = "rgeat";
  string s3 = "rgtae";
  string s4 = "eat";
  string s5 = "tae";
  string s6 = "abcdefghijklmnopq";
  string s7 = "efghijklmnopqcadb";
  string s8 = "ccabcbabcbabbbbcbb";
  string s9 = "bbbbabccccbbbabcba";
  string s10 = "ymjmfxshglxwrrgufcvvzjuietjzzz";
  string s11 = "fxczujvmwizrzgxgjmvzelyjthusrf";
  string s12 = "xstjzkfpkggnhjzkpfjoguxvkbuopi";
  string s13 = "xbouipkvxugojfpkzjhnggkpfkzjts";

  assert(solution.isScramble(s1, s2));
  assert(solution.isScramble(s1, s3));
  assert(solution.isScramble(s4, s5));
  assert(!solution.isScramble(s6, s7));
  assert(!solution.isScramble(s8, s9));
  assert(!solution.isScramble(s10, s11));
  assert(solution.isScramble(s12, s13));
}
