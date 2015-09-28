/*
 * =====================================================================================
 *
 *       Filename:  combinations.cpp
 *
 *    Description:  Given two integers n and k, return all possible combinations
 *                  of k numbers out of 1 ... n.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 09:36:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  vector<vector<int> > combine(int s, int n, int k) {
      vector<vector<int> > res;
      if (k == 0) {
        res.push_back(vector<int>());
        return res;
      }
      if (k == n) {
        res.push_back(vector<int>());
        for (int i = s; i < s+n; i++)
          res.back().push_back(i);
        return res;
      }

      vector<vector<int> > withouts = combine(s+1, n-1, k);
      vector<vector<int> > withs = combine(s+1, n-1, k-1);

      for (int j = 0; j < withs.size(); j++) {
        withs[j].insert(withs[j].begin(), s);
        res.push_back(withs[j]);
      }

      for (int j = 0; j < withouts.size(); j++)
        res.push_back(withouts[j]);

      return res;
  }
  public:
    vector<vector<int> > combine(int n, int k) {
      return combine(1, n, k);
    }
};

int
main()
{
  Solution solution;
  vector<vector<int> > res = solution.combine(3,2);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
