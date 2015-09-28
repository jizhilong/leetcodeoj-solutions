/*
 * =====================================================================================
 *
 *       Filename:  lcp.cpp
 *
 *    Description:  Write a function to find the longest common prefix string
 *                  amongst an array of strings.
 *
 *        Version:  1.0
 *        Created:  03/25/2014 08:31:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
      if (strs.empty()) return "";
      int rightMost = strs[0].length() - 1;
      for (int i = 1; rightMost >= 0 && i < strs.size(); i++) {
        int j;
        for (j = 0; j < strs[i].length() && j <= rightMost && strs[i][j] == strs[0][j]; j++);
        rightMost = --j;
      }

      return strs[0].substr(0, rightMost+1);
    }
};

int
main()
{
  vector<string> strs = {"abc", "abcd"};
  Solution solution;
  cout << solution.longestCommonPrefix(strs) << endl;
}

