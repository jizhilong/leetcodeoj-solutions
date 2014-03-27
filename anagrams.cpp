/*
 * =====================================================================================
 *
 *       Filename:  anagrams.cpp
 *
 *    Description:  Given an array of strings, return all groups of strings that
 *                  that are anagrams.Note: All inputs will be in lower-case.
 *
 *        Version:  1.0
 *        Created:  03/27/2014 10:27:30 PM
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
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<string> anagrams(vector<string> &strs) {
      unordered_map<string, int> map;
      vector<string> res;

      for (int i = 0; i < strs.size(); i++) {
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        if (map.find(tmp) == map.end()) {
          map[tmp] = i;
        } else {
          if (map[tmp] != -1) {
            res.push_back(strs[map[tmp]]);
            map[tmp] = -1;
          }
          res.push_back(strs[i]);
        }
      }
      return res;
    }
};

int
main()
{
  vector<string> strs = {"dog", "cat", "god", "tac"};
  Solution solution;
  vector<string> res = solution.anagrams(strs);
  for (auto it = res.begin(); it != res.end(); it++)
    cout << *it << endl;
}
