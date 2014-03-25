/*
 * =====================================================================================
 *
 *       Filename:  combination_sum.cpp
 *
 *    Description:  Given a set of candidate numbers and a target number, find 
 *                  all unique combinations in C where the candidate numbers 
 *                  sums to T. The same repeated number may be chosen from C
 *                  unlimited number of times.
 *
 *        Version:  1.0
 *        Created:  03/25/2014 09:02:54 AM
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
  private:
    vector<vector<int> > 
    combinationSum(vector<int> &candidates, int s, int target) {
      vector<vector<int> > res;

      if (target == 0) {
        res.push_back(vector<int>());
        return res;
      }

      if (s == candidates.size() || candidates[s] > target) {
        return res;
      }

      int most = target / candidates[s];
      for (int i = 0; i <= most; i++) {
        vector<vector<int> > tail = combinationSum(candidates, s+1, target - i*candidates[s]);
        for (int j = 0; j < tail.size(); j++) {
          res.push_back(vector<int>(i, candidates[s]));
          for (int k = 0; k < tail[j].size(); k++) {
            res.back().push_back(tail[j][k]);
          }
        }
      }

      return res;
    }

  public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
      sort(candidates.begin(), candidates.end());
      return combinationSum(candidates, 0, target);
    }
};

int
main()
{
  vector<int> candidates = {8,7,4,3};
  int target = 11;
  Solution solution;
  vector<vector<int> > res = solution.combinationSum(candidates, target);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}

