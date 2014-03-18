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
#include <queue>
#include <assert.h>

using namespace std;

class Solution {
  private:
    string s1, s2;

    bool equal(int i1, int j1, int i2, int j2) {
      for (; i1 < j1 && i2 < j2 && s1[i1] == s2[i2]; i1++, i2++);
      return i1 == j1;
    }

    bool _isScramble(int i1, int j1, int i2, int j2) {
      if (j1 == i1)
        return true;
      if (j1 == i1 + 1)
        return s1[i1] == s2[i2];
      if (j1 == i1 + 2)
        return s1[i1] == s2[i2+1] && s1[i1+1] == s2[i2];

      if (equal(i1, j1, i2, j2))
        return true;

      int len = j1 - i1;
      for (int i = 1; i < len; i++) {
        if ((_isScramble(i1, i1+i, i2, i2+i) && _isScramble(i1+i, j1, i2+i, j2)) || \
           (_isScramble(i1, i1+i, i2+len-i, j2) && _isScramble(i1+i, j1, i2, i2+len-i)))
             return true;
      }

      return false;
    }
  public:
    bool isScramble(string str1, string str2) {
      s1 = str1; s2 = str2;
      return _isScramble(0, s1.length(), 0, s2.length());
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

  assert(solution.isScramble(s1, s2));
  assert(solution.isScramble(s1, s3));
  assert(solution.isScramble(s4, s5));
  assert(!solution.isScramble(s6, s7));
}
