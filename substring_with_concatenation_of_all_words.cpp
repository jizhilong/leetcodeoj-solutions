/*
 * =====================================================================================
 *
 *       Filename:  substring_with_concatenation_of_all_words.cpp
 *
 *    Description:  You are given a string, S, and a list of words, L, that are
 *                  all of the same length.Find all starting indicies of 
 *                  substrings in S that is a concatenation of each word in L
 *                  exactly once and without any intervening characters.
 *
 *                  For example, given:
 *                  S: "barfoothefoobarman"
 *                  L: ["foo", "bar"]
 *                  You should return the indices:[0,9]
 *
 *        Version:  1.0
 *        Created:  04/26/2014 03:16:05 PM
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
#include <assert.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &L) {
      unordered_map<string, int> map;
      vector<int> ret;
      if (L.empty())
        return ret;
      int len = L[0].size();
      int total = L.size() * len;
      if (s.length() < total)
        return ret;

      for (int i = 0; i < L.size(); i++) {
        if (map.find(L[i]) == map.end()) {
          map[L[i]] = 1;
        } else {
          map[L[i]]++;
        }
      }

      for (int i = 0; i <= s.length() - total; i++) {
        unordered_map<string, int> tmpmap = map;
        int tmptotal = L.size();
        for (int j = i; j < i + total; j += L[0].size()) {
          string tmp = s.substr(j, len);
          if (tmpmap.find(tmp) == tmpmap.end() || tmpmap[tmp] == 0) {
            break;
          } else {
            tmpmap[tmp]--;
            tmptotal--;
          }
          if (tmptotal == 0)
            ret.push_back(i);
        }
      }

      return ret;
    }
};

int
main()
{
  vector<string> L = {"a", "a"};
  string s = "a";
  Solution solution;
  vector<int> res = solution.findSubstring(s, L);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
}
