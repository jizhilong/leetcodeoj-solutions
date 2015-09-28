/*
 * =====================================================================================
 *
 *       Filename:  len_of_last_word.cpp
 *
 *    Description:  Given a string s consists of upper/lower-case alphabets and
 *                  empty space characters ' ',return the length of last word in
 *                  the string.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 03:37:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLastWord(const char *s) {
      const char *tail;
      for (tail = s; *tail != '\0'; tail++);
      for (tail-- ; tail > s-1 && *tail == ' '; tail--);
      const char *head;
      for (head = tail; head > s - 1 && *head != ' '; head--);
      return tail - head;
    }
};

int
main()
{
  Solution solution;
  cout << solution.lengthOfLastWord("Hello World") << endl;
  cout << solution.lengthOfLastWord("") << endl;
  cout << solution.lengthOfLastWord("  h ") << endl;
}
