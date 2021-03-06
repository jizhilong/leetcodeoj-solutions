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
#include <string.h>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
  private:
    string s1, s2;
    short *dp;
    int slen;

    inline bool equal(int i1, int i2, int len) {
      int j1 = i1+len, j2 = i2 + len;
      for (; i1 < j1 && i2 < j2 && s1[i1] == s2[i2]; i1++, i2++);
      return i1 == j1;
    }

    inline bool sameChars(int i1, int i2, int len, int dpclen) {
      vector<int> chars(26, 0);
      int j1 = i1+len, j2 = i2 + len;

      for (; i1 < j1 && i2 < j2; i1++, i2++) {
        chars[s1[i1] - 'a']++;
        chars[s2[i2] - 'a']--;
      }

      int i;
      for (i = 0; i < 26 && chars[i] == 0; i++);

      return i == 26;
    }

    bool _isScramble(int i1, int i2, int len) {
      short *dpp = dp + (len-1)*slen*slen+ i1*slen+ i2;
      if (*dpp == 1)
        return false;
      if (*dpp == 2)
        return true;

      if (0 == len)
        goto succeed;

      if (equal(i1, i2, len)) 
        goto succeed;

      if (!sameChars(i1, i2, len, dpp - dp))
        goto failed;

      for (int i = 1; i < len; i++) {
        if ((_isScramble(i1, i2, i) && _isScramble(i1+i, i2+i, len - i)) || \
           (_isScramble(i1, i2+len-i, i) && _isScramble(i1+i, i2, len-i)))
          goto succeed;
      }

failed:
      *dpp = 1;
      return false;
succeed:
      *dpp = 2;
      return true;
    }

  public:
    bool isScramble(string str1, string str2) {
      s1 = str1; s2 = str2;
      if (s1.length() != s2.length())
        return false;
      slen = s1.length();
      int dplen = slen*slen*slen;
      dp = (short*)malloc(sizeof(short)*dplen);
      memset((void *)dp, 0, dplen*sizeof(short));

      return _isScramble(0, 0, slen);
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
