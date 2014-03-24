/*
 * =====================================================================================
 *
 *       Filename:  search_for_range.cpp
 *
 *    Description:  Given a sorted array of integers, find the starting and
 *                  ending position of a given target value.Your algorithm's
 *                  running time complexity must be in the order of O(lgn).If
 *                  the target is not found in the array, return [-1, -1].
 *
 *        Version:  1.0
 *        Created:  03/24/2014 08:39:14 PM
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

using namespace std;

class Solution {
  public:
    vector<int> searchRange(int A[], int n, int target) {
      vector<int> res(2, -1);
      bool found = false;
      int lo = 0, hi = n - 1;

      while (lo <= hi) {
        int mid = (lo+hi) / 2;
        if (A[mid] == target) {
          found = true;
          break;
        } else if (A[mid] < target) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }

      if (!found)
        return res;
      int hiback = hi;
      int loback = lo;
      hi = (lo+hi)/2;
      while (true) {
        int mid = (lo+hi)/2;
        if (A[mid] < target) {
          lo = mid+1;
        } else if (mid == 0 || A[mid-1] < A[mid]) {
          res[0] = mid;
          break;
        } else {
          hi = mid - 1;
        }
      }

      lo = (hiback+loback) / 2;
      hi = hiback;
      while (true) {
        int mid = (lo+hi)/2;
        if (A[mid] > target) {
          hi = mid-1;
        } else if (mid == n-1 || A[mid+1] > A[mid]) {
          res[1] = mid;
          break;
        } else {
          lo = mid + 1;
        }
      }

      return res;

    }
};

int
main() {
  int A[] = {5,7,7,8,8,10};
  Solution solution;
  vector<int> res = solution.searchRange(A, sizeof(A)/sizeof(int), 8);
  cout << res[0] << " " << res[1] << endl;
}
