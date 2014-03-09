/*
 * =====================================================================================
 *
 *       Filename:  reverse_words.cpp
 *
 *    Description:  Given an input string, reverse the string word by word.
 *                  For example.
 *                  Given s = "the sky is blue".
 *                  return "blue is sky the".
 *
 *        Version:  1.0
 *        Created:  03/09/2014 07:29:11 PM
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

using namespace std;

class Solution {
  private:
    void reverse(string &str, int s, int e) {
      char c;
      for (; s < e; s++, e--) {
        c = str[e];
        str[e] = str[s];
        str[s] = c;
      }
    }

  public:
    void reverseWords(string &s) {
      bool spacing = true;
      int i, j;
      for (i = 0, j = 0; i < s.length(); i++) {
        if (s[i] != ' ' || !spacing) {
          s[j++] = s[i];
          spacing = (s[i] == ' ');
        }
      }
      if (s[j-1] == ' ')
        j--;
      s.resize(j);

      reverse(s, 0, j-1);

      int start = 0;
      for (int i = 0; i < j; i++) {
          if (s[i] == ' ') {
            reverse(s, start, i-1);
            start = i+1;
          }
      }

      reverse(s, start, j-1);
    }
};

int
main(int argc, char *argv[])
{
  string s = "";
  Solution solution;
  cout << s << endl;
  solution.reverseWords(s);
  cout << s << endl;
}
