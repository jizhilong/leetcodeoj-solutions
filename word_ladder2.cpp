/*
 * =====================================================================================
 *
 *       Filename:  word_ladder2.cpp
 *    Description:  another version of problem word ladder 2. Find all shortest solutions.
 *
 *        Version:  1.0
 *        Created:  03/09/2014 10:31:51 PM
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
#include <queue>
#include <utility>
#include <unordered_set>
#include <iostream>

using namespace std;
typedef pair<int, char> t;

class Solution {
  public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
      queue<vector<t> > trans;
      vector<vector<t> > res;
      trans.push(vector<t>());

      while (!trans.empty()) {
        vector<t> tran = trans.front(); trans.pop();

        string tmp = start;

        for (int i = 1; i < tran.size(); i++) {
          tmp[tran[i].first] = tran[i].second;
        }

        if (!res.empty() && tran.size() >= res[0].size())
          break;

        for (int i = 0; i < tmp.length(); i++) {
          char tc = tmp[i];
          for (char c = 'a'; c <= 'z'; c++) {
            if (c != tc) {
              tmp[i] = c;
              if (tmp == end) {
                res.push_back(tran);
                res.back().push_back(t(i, c));
                goto endloop;
              }
              if (dict.find(tmp) != dict.end()) {
                trans.push(tran);
                trans.back().push_back(t(i, c));
              }
              tmp[i] = tc;
            }
          }
        }
endloop:;
      }

      vector<vector<string> > result;

      for (int i = 0; i < res.size(); i++) {
        result.push_back(vector<string>());
        result.back().push_back(start);
        for (int j = 0; j < res[i].size(); j++) {
          string tmp = result.back().back();
          tmp[res[i][j].first] = res[i][j].second;
          result.back().push_back(tmp);
        }
      }

      return result;
    }
};

int
main(int argc, char *argv[])
{

  string start = "hit";
  string end = "cog";
  unordered_set<string> dict;
  dict.insert("hot");
  dict.insert("dot");
  dict.insert("dog");
  dict.insert("lot");
  dict.insert("log");

  Solution solution;
  vector<vector<string> > res = solution.findLadders(start, end, dict);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}

