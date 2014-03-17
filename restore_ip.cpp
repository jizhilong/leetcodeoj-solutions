/*
 * =====================================================================================
 *
 *       Filename:  restore_ip.cpp
 *
 *    Description:  Given a string containing only digits, restore it by return
 *                  ing all possible valid IP address combinations.
 *                  For example, Given "25525511135", return 
 *                  ["255.255.11.135","255.255.111.35"]
 *
 *        Version:  1.0
 *        Created:  03/17/2014 09:18:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      int len = s.length();
      if (len < 4 || len > 12)
        return res;
      stack<vector<int> > stk;
      stk.push(vector<int>(1, 0));

      while (!stk.empty()) {
        vector<int> pref = stk.top(); stk.pop();
        int last = pref.back();
        if (pref.size() == 5) {
          if (last == len) {
            stringstream ss;
            for (int i = 0; i < 3; i++) {
              ss << s.substr(pref[i], pref[i+1] - pref[i]) << ".";
            }
            ss << s.substr(pref[3], pref[4] - pref[3]);
            res.push_back(ss.str());
          }
          continue;
        }

        if (last == len)
          continue;

        if (s[last] == '0') {
          pref.push_back(last+1);
          stk.push(pref);
          continue;
        }

        for (int j = last+1; j <= len && stoi(s.substr(last, j-last)) <= 255; j++) {
          vector<int> tmp = pref;
          tmp.push_back(j);
          stk.push(tmp);
        }
      }
    return res;
    }
};

int
main() {
  string str = "010010";
  Solution solution;
  vector<string> res = solution.restoreIpAddresses(str);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << endl;
}

