/*
 * =====================================================================================
 *
 *       Filename:  subsets2.cpp
 *
 *    Description:  Given a collection of integers that might contain duplicates
 *                  return all possible subsets.
 *                  Note:
 *                      Elements in a subset must be in non-descending order
 *                      The solution set must not contain duplicate subsets.
 *                  
 *
 *        Version:  1.0
 *        Created:  03/17/2014 11:13:54 AM
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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
      vector<vector<int> > res;
      sort(S.begin(), S.end());
      res.push_back(vector<int>());
      int i = 0;
      while (i < S.size()) {
        int j;
        int k = res.size();
        for (j = i+1; j < S.size() && S[j] == S[i]; j++);
        int count = j - i;
        for (int l = 0; l < k; l++) {
          for (int m = 1; m <= count; m++) {
            vector<int> tmp = res[l];
            for (int h = 0; h < m; h++)
              tmp.push_back(S[i]);
            res.push_back(tmp);
          }
        }
        i = j;
      }
      return res;
    }
};

int
main()
{
  vector<int> v = {1,2,2};
  Solution solution;
  vector<vector<int> > res = solution.subsetsWithDup(v);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
