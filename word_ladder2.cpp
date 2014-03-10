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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dic) {
      vector<string> dict(dic.begin(), dic.end());
      dict.push_back(end);
      dict.insert(dict.begin(), start);
      unordered_map<string, vector<int> > map;
      int starti = 0, endi = dict.size() - 1;

      for (int i = 1; i < dict.size(); i++) {  /* record the variations of every word in dict */
          string tmp = dict[i];
          for (int j = 0; j < tmp.length(); j++) {
            tmp[j] = '\0';
            if (map.find(tmp) == map.end())
              map[tmp] = vector<int>();
            map[tmp].push_back(i);
            tmp[j] = dict[i][j];
          }
      }

      queue<int> q;
      queue<vector<int> > trans;
      vector<vector<int> > res;

      q.push(starti);
      trans.push(vector<int>());

      while (!q.empty()) {
        int tmpi = q.front(); q.pop();
        string tmp = dict[tmpi];
        vector<int> tran = trans.front(); trans.pop();

        tran.push_back(tmpi);

        if (!res.empty() && tran.size() > res[0].size())
          break;

        if (tmpi == endi) {
          res.push_back(tran);
          continue;
        }

        for (int i = 0; i < tmp.length(); i++) {
          char tc = tmp[i];
          tmp[i] = '\0';
          if (map.find(tmp) == map.end()) {
            tmp[i] = tc;
            continue;
          }
          for (auto it = map[tmp].begin(); it != map[tmp].end(); it++) {
            q.push(*it);
            trans.push(tran);
          }
          tmp[i] = tc;
        }
      }

      vector<vector<string> > result;
      if (res.empty())
        return result;

      for (int i = 0; i < res.size(); i++) {
        result.push_back(vector<string>());
        for (int j = 0; j < res[i].size(); j++) {
          result.back().push_back(dict[res[i][j]]);
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

