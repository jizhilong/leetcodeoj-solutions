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
    vector<string> scrambles(string s) {
      if (s.length() <= 1)
         return vector<string>();
      vector<string> res;
      for (int i = 1; i < s.length(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i, s.length() - i);
        vector<string> lscrambles = scrambles(left);
        vector<string> rscrambles = scrambles(right);
        res.push_back(right + left);
        for (auto itl = lscrambles.begin(); itl != lscrambles.end(); itl++) {
          for (auto itr = rscrambles.begin(); itr != rscrambles.end(); itr++) {
            res.push_back(left+*itr);
            res.push_back(*itl+right);
            res.push_back(*itl+*itr);
          }
        }
      }

      return res;
    }

  public:
    bool isScramble(string s1, string s2) {
      vector<string> scrambles1 = scrambles(s1);
      for (auto it = scrambles1.begin(); it != scrambles1.end(); it++) {
        if (*it == s2)
          return true;
      }
      return false;
    }
};

int
main()
{
  Solution solution;
  string s1 = "great";
  string s2 = "rgeat";
  string s3 = s1;

  assert(solution.isScramble(s1, s2));
}
