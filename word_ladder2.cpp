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
#include <fstream>

using namespace std;

struct TransNode {
  int str;
  int lvl;
  TransNode *parent;

  TransNode(int s):str(s), lvl(0), parent(NULL){};
  TransNode(int s, TransNode *p):str(s), lvl(p->lvl+1), parent(p){};
};

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

      queue<TransNode*> trans;
      vector<vector<string> > res;
      vector<int> set(dict.size(), -1);
      trans.push(new TransNode(starti));
      set[starti] = 0;

      while (!trans.empty()) {
        TransNode *tran = trans.front(); trans.pop();
        int tmpi = tran->str;
        string tmp = dict[tmpi];

        if (!res.empty() && tran->lvl >= res[0].size() - 1)
          break;

        for (int i = 0; i < tmp.length(); i++) {
          tmp[i] = '\0';

          for (auto s = map[tmp].begin(); s != map[tmp].end(); s++) {
            if (dict[*s] == end) {
              res.push_back(vector<string>(tran->lvl+2));
              res.back()[tran->lvl+1] = end;
              for (TransNode *t = tran; t; t = t->parent)
                res.back()[t->lvl] = dict[t->str];
              break;
            }

            if (res.empty() && (set[*s] == -1 ||  set[*s] == tran->lvl+1)) {
              trans.push(new TransNode(*s, tran));
              set[*s] = tran->lvl+1;
            }
          }

          tmp[i] = dict[tmpi][i];
        }
      }

      return res;
    }
};

int
main(int argc, char *argv[])
{
  string start;
  string end;
  string tmp;
  unordered_set<string> dict;

  getline(cin, start);
  getline(cin, end);

  while (getline(cin, tmp)) {
    dict.insert(tmp);
  }

  Solution solution;
  vector<vector<string> > res = solution.findLadders(start, end, dict);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  cout << res.size() << " " << res[0].size() << endl;
}

