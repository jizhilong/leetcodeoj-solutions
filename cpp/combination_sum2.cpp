/*
 * =====================================================================================
 *
 *       Filename:  combination_sum2.cpp
 *
 *    Description:  Given a collection of candidate numbers and a target number
 *                  , find all unique combinations in C where the candidate
 *                  numbers sums to T.Each number in C may only be used once in
 *                  the combination.
 *                  Note:
 *                    All numbers will be positive integers.
 *                    Elements in a combination must be non-decreasing order.
 *                    The solution set must not contain duplicate combinations.
 *
 *        Version:  1.0
 *        Created:  03/27/2014 08:23:43 AM
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
#include <algorithm>

using namespace std;

class Solution {
  vector<vector<int> > combinationSum2(vector<int> &num, int s, int target) {
    vector<vector<int> > res;
    if (target == 0) {
      res.push_back(vector<int>());
      return res;
    }

    if (s == num.size() || num[s] > target) {
      return res;
    }

    int len;
    for (len=1; s+len < num.size() && num[len+s] == num[s]; len++);

    for (int i = 0; i <= len; i++) {
      vector<vector<int> > withis = combinationSum2(num, s+len, target-i*num[s]);
      for (int j = 0; j < withis.size(); j++) {
        for (int k = 0; k < i; k++)
          withis[j].insert(withis[j].begin(), num[s]);
          res.push_back(withis[j]);
      }
    }

    return res;
  }
  public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      return combinationSum2(num, 0, target);
    }
};

int
main()
{
  vector<int> num = {10,1,2,7,6,1,5};
  Solution solution;
  vector<vector<int> > res = solution.combinationSum2(num, 8);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
