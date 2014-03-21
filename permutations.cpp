/*
 * =====================================================================================
 *
 *       Filename:  permutations.cpp
 *
 *    Description:  Given a collection of numbers, return all possible permutations.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 01:42:38 PM
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
  public:
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > res;
      if (num.empty()) {
        return res;
      }
      if (num.size() == 1) {
        res.push_back(num);
        return res;
      }
      int head = num[0];
      vector<int> tail(num.begin()+1, num.end());
      vector<vector<int> > tailperm = permute(tail);
      for (int i = 0; i < tailperm.size(); i++) {
        for (int j = 0; j <= tailperm[i].size(); j++) {
          res.push_back(vector<int>());
          for (int k = 0; k < j; k++)
            res.back().push_back(tailperm[i][k]);
          res.back().push_back(head);
          for (int k = j; k < tailperm[i].size(); k++)
            res.back().push_back(tailperm[i][k]);
        }
      }
      return res;
    }
};

int
main()
{
  vector<int> vec = {1,2,3};
  vector<vector<int> > res;
  Solution solution;
  res = solution.permute(vec);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
