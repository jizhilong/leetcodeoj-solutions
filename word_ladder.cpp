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
  bool similar(string s1, string s2) {
    bool diff = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
          if (diff)
            return false;
          diff = true;
        }
    }

    return diff;
  }

  public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
      dict.insert(start);
      dict.insert(end);
      unordered_map<string, vector<string> > map;

      for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
          map[*it] = vector<string>();
      }

      for (auto it = dict.begin(); it != dict.end(); it++) {
        for (auto it1 = next(it); it1 != dict.end(); it1++) {
          if (similar(*it, *it1)) {
            map[*it].push_back(*it1);
            map[*it1].push_back(*it);
          }
        }
      }

      unordered_set<string> set;
      queue<string> q;
      queue<int> lens;
      int res = -1;

      set.insert(start);
      q.push(start);
      lens.push(1);

      while (!q.empty()) {
        string str = q.front(); q.pop();
        int len = lens.front(); lens.pop();

        if (str == end) {
          if (res == -1 || res > len)
            res = len;
          continue;
        }

        for (auto it = map[str].begin(); it != map[str].end(); it++) {
          if (set.find(*it) == set.end()) {
            q.push(*it);
            lens.push(len+1);
            set.insert(*it);
          }
        }
      }

      return res == -1 ? 0 : res;
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

