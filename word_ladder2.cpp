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
#include <iostream>

using namespace std;

struct TransNode {
  string str;
  int lvl;
  TransNode *parent;

  TransNode(string &s):str(s), lvl(0), parent(NULL){};
  TransNode(string &s, TransNode *p):str(s), lvl(p->lvl+1), parent(p){};
};

class Solution {
  public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
      queue<TransNode*> trans;
      vector<vector<string> > res;
      trans.push(new TransNode(start));

      while (!trans.empty()) {
        TransNode *tran = trans.front(); trans.pop();
        string tmp = tran->str;

        if (!res.empty() && tran->lvl >= res[0].size() - 1)
          break;

        for (int i = 0; i < tmp.length(); i++) {
          char tc = tmp[i];
          for (char c = 'a'; c <= 'z'; c++) {
            if (c != tc) {
              tmp[i] = c;
              if (tmp == end) {
                res.push_back(vector<string>(tran->lvl+2));
                res.back()[tran->lvl+1] = end;
                for (TransNode *t = tran; t; t = t->parent)
                  res.back()[t->lvl] = t->str;
                goto endloop;
              }
              if (dict.find(tmp) != dict.end()) {
                trans.push(new TransNode(tmp, tran));
              }
              tmp[i] = tc;
            }
          }
        }
endloop:;
      }

      return res;
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

