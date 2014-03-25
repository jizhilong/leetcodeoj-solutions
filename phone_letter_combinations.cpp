/*
 * =====================================================================================
 *
 *       Filename:  phone_letter_combinations.cpp
 *
 *    Description:  Given a digit string, return all possible letter 
 *                  combinations that the number could represent.A mapping of
 *                  digit to letters(just like on the telephone buttons is
 *                  given below.
 *
 *        Version:  1.0
 *        Created:  03/25/2014 09:57:03 AM
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
#include <string>

using namespace std;

static const char* maps[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      queue<string> q;
      queue<int> lens;
      q.push("");
      lens.push(0);

      while (!q.empty()) {
        string s = q.front(); q.pop();
        int len = lens.front(); lens.pop();
        if (len == digits.length()) {
          res.push_back(s);
          continue;
        }
        int digit = digits[len] - '0';
        for (const char *c = maps[digit]; *c != '\0'; c++) {
          q.push(s+*c);
          lens.push(len+1);
        }
      }
      return res;
    }
};


int
main()
{
  Solution solution;
  vector<string> res;
  res = solution.letterCombinations("23");
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << endl;
}
