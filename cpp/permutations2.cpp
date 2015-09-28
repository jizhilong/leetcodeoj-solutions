/*
 * =====================================================================================
 *
 *       Filename:  permutations2.cpp
 *
 *    Description:  Given a collection of numbers that contain duplicates, 
 *                  reurn all unique permutations.For example,
 *                  [1,1,2] have the folloing unique permutations:
 *                  [1,1,2],[1,2,1], and [2,1,1]
 *
 *        Version:  1.0
 *        Created:  03/26/2014 07:56:20 PM
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
  private:
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

  vector<vector<int> > _permutateUnique(vector<int> &num, int s) {
      vector<vector<int> > res;
      if (s == num.size()) {
        res.push_back(vector<int>());
        return res;
      }

      int i;
      for (i = s+1; i < num.size() && num[s] == num[i]; i++);  /* count how many num[s] in the vector */
      vector<vector<int> > combs = combine(0, num.size() - s, i - s); /* the places num[s]s will be in the permutations. */
      vector<vector<int> > tail = _permutateUnique(num, i);   /* the permutations of other numbers. */

      for (int i = 0; i < tail.size(); i++) {
        for (int j = 0; j < combs.size(); j++) {
          res.push_back(vector<int>());
          int m = 0, n = 0;
          while (n < combs[j].size()) {
            while (m+n < combs[j][n]) {
              res.back().push_back(tail[i][m++]);
            }
            res.back().push_back(num[s]);
            n++;
          }

          while (m < tail[i].size()) {
            res.back().push_back(tail[i][m++]);
          }
        }
      }

      return res;
  }

  public:
    vector<vector<int> > permutateUnique(vector<int> &num) {
      sort(num.begin(), num.end());
      return _permutateUnique(num, 0);
    }
};

int
main() {
  vector<int> num = {};
  vector<vector<int> > res;
  Solution solution;
  res = solution.permutateUnique(num);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
