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
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
      dict.insert(end);
      unordered_map<string, vector<string> > map;

      for (auto it = dict.begin(); it != dict.end(); it++) {
          string tmp = *it;
          for (int i = 0; i < tmp.length(); i++) {
            tmp[i] = '\0';
            if (map.find(tmp) == map.end())
              map[tmp] = vector<string>();
            map[tmp].push_back(*it);
            tmp[i] = (*it)[i];
          }
      }

      unordered_set<string> set;
      queue<string> q;
      queue<vector<string> > trans;
      vector<vector<string> > res;
      int min = -1;

      set.insert(start);
      q.push(start);
      trans.push(vector<string>());

      while (!q.empty()) {
        string tmp = q.front(); q.pop();
        vector<string> tran = trans.front(); trans.pop();

        tran.push_back(tmp);

        if (!res.empty() && tran.size() > res[0].size())
          break;

        if (tmp == end) {
          if (res.empty() || tran.size() == res[0].size()) {
            res.push_back(tran);
            continue;
          } else {
            break;
          }
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
            set.insert(*it);
            trans.push(tran);
          }
          tmp[i] = tc;
        }
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
  cout << solution.findLadders(start, end, dict).size() << endl;
}

