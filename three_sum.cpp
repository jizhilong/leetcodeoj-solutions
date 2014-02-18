/*
 * =====================================================================================
 *
 *       Filename:  three_sum.cpp
 *
 *    Description: Given an array S of n integers, find three integers in S such that the
 *                 sum is closest to a given number, target. Return the sum of the three 
 *                 integers. You may assume that each input would have exactly one solution.
 *                 -------------------------------------------------------------------------
 *                 for example, given array S = {-1 2 1 -4}, and target = 1.
 *                 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). 
 *
 *        Version:  1.0
 *        Created:  02/18/2014 06:46:58 PM
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
    int abs(int n) {
      return n < 0 ? -n : n;
    }

    int bin_search(vector<int> &num, int target, int lo) {
      int hi = num.size() - 1;
      int mid;
      int m;

      while (lo < hi - 1) {
        mid = lo + ((hi - lo) >> 1);
        m = num[mid];

        if (target == m) {
          return m;
        } else if (target < m) {
          hi = mid;
        } else {
          lo = mid;
        }
      }

      return abs(target - num[lo]) < abs(num[hi] - target) ? num[lo] : num[hi];
    }

public:

    int threeSumClosest(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      int res = num[0] + num[1];
      res = bin_search(num, target - res, 2) + res;

      for (int i = 0; i < num.size(); i++)
        for (int j = i+1; j < num.size() - 1; j++) {
          int tmp = num[i] + num[j];

          tmp += bin_search(num, target - tmp, j + 1);

          if (abs(tmp - target) < abs(res - target))
            res = tmp;
        }

      return res;
    }
};


int
main(int argc, char *argv[])
{
  int nums[] = {-1, 2, 1, -4};
  int target = 1;
  vector<int> S(nums, nums + 4);
  Solution solution;
  cout << solution.threeSumClosest(S, 0) << endl;
}
