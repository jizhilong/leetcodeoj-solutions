/*
 * =====================================================================================
 *
 *       Filename:  subsets.cpp
 *
 *    Description:  Given a set of distinct integers, S, return all possible subsets
 *
 *
 *        Version:  1.0
 *        Created:  03/24/2014 04:14:40 PM
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
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int> > subsets(vector<int> &S) {
      vector<vector<int> > res;
      sort(S.begin(), S.end());
      res.push_back(vector<int>());
      int i = 0;
      while (i < S.size()) {
        int k = res.size();
        for (int l = 0; l < k; l++) {
          vector<int> tmp = res[l];
          tmp.push_back(S[i]);
          res.push_back(tmp);
        }
        i++;
      }
      return res;
    }
};

int
main()
{
  vector<int> v = {1,2};
  Solution solution;
  vector<vector<int> > res = solution.subsets(v);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
