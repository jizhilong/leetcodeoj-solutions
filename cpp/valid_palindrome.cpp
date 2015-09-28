/*
 * =====================================================================================
 *
 *       Filename:  valid_palindrome.cpp
 *
 *    Description:  Given a string, determin if it is a palindrome, considering
 *                  only alphanumeric characters and ignoreing cases. For 
 *                  example:
 *                  ------------------------------------------------------------
 *                  "A man, a plan, a canal: Panama" is a palindrome.
 *                  "race a car" is not a palindrome.
 *                  -----------------------------------------------------------
 *                  Note:
 *                  Have you consider that the string might be empty?
 *                  For the purpose of this problem, we define empty string as
 *                  valid palindrome.
 *
 *        Version:  1.0
 *        Created:  03/12/2014 12:59:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Solution {
  private:
    bool isSpace(char c) {
      return !(isalnum(c));
    }

    bool equali(char c1, char c2) {
      return c1 == c2 || c2 == c1 + 32 || c1 == c2 + 32;
    }

  public:
    bool isPalindrome(string s) {
      if (s.length() <= 1)
        return true;

      for (int i = 0, j = s.length() - 1; i < j;) {
        if (isSpace(s[i])) {
          i++;
        } else if (isSpace(s[j])) {
          j--;
        } else if (equali(s[i], s[j])) {
          i++;j--;
        } else {
          return false;
        }
      }

      return true;
    }
};

int
main(int argc, char *argv[]) {
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "race a car";
  string s3 = "";
  string s4 = "    ";
  Solution solution;
  cout << solution.isPalindrome(s1) << endl;
  cout << solution.isPalindrome(s2) << endl;
  cout << solution.isPalindrome(s3) << endl;
  cout << solution.isPalindrome(s4) << endl;
}
