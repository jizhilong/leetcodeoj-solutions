/*
 * =====================================================================================
 *
 *       Filename:  word_ladder.cpp
 *
 *    Description:  Given two words (start and end), and a dictionary, find the
 *                  length of shortest transformation sequence from start to end
 *                  such that: 
 *                  1. Only one letter can be changed at a time.
 *                  2. Each intermediate word must exist in the dictionary
 *                  For example, Given:
 *                    start = "hit"
 *                    end = "cog"
 *                    dict = ["hot", "dot", "dog", "lot", "log"]
 *                    As one shortest transformation is "hit" -> "hot" -> "dot"
 *                    -> dog -> cog. Return its length 5.
 *                  Note:
 *                    Return 0 if there is no such transformation sequence.
 *                    All words have the same length.
 *                    All words contain only lowercase alphabetic characters.
 *
 *        Version:  1.0
 *        Created:  03/09/2014 07:21:41 PM
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
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
  public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
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
      queue<int> lens;

      set.insert(start);
      q.push(start);
      lens.push(1);

      while (!q.empty()) {
        string tmp = q.front(); q.pop();
        int len = lens.front(); lens.pop();

        if (tmp == end) {
          return len;
        }

        for (int i = 0; i < tmp.length(); i++) {
          char tc = tmp[i];
          tmp[i] = '\0';
          if (map.find(tmp) == map.end()) {
            tmp[i] = tc;
            continue;
          }
          for (auto it = map[tmp].begin(); it != map[tmp].end(); it++) {
            if (set.find(*it) == set.end()) {
              q.push(*it);
              set.insert(*it);
              lens.push(len+1);
            }
          }
          tmp[i] = tc;
        }
      }

      return 0;
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
  cout << solution.ladderLength(start, end, dict) << endl;
}

