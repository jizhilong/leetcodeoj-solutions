/*
 * =====================================================================================
 *
 *       Filename:  generate_parentheses.cpp
 *
 *    Description:  Given n pairs of parentheses, write a function to generate
 *                  all combinations of well-formed parentheses.For example, 
 *                  given n = 3, a solution set is: "((()))", "(()())","(())()",
 *                  "()(())","()()()"
 *
 *        Version:  1.0
 *        Created:  03/22/2014 09:13:20 PM
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
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      queue<string> q;
      queue<int> pairs;
      vector<string> res;
      if (n == 0)
        return res;

      q.push("");
      pairs.push(0);
      while (!q.empty()) {
        string str = q.front(); q.pop();
        int p = pairs.front(); pairs.pop();

        if (p == n) {
          res.push_back(str);
          continue;
        }

        if (str.length() - p < n) {
          q.push(str+"(");
          pairs.push(p);
        }

        if (2*p < str.length()) {
          q.push(str+")");
          pairs.push(p+1);
        }
      }
      return res;
    }
};

int
main(int argc, char *argv[])
{
  vector<string> res;
  Solution solution;
  int n = atoi(argv[1]);
  res = solution.generateParenthesis(n);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
}
