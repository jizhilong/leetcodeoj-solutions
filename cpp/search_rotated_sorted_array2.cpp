/*
 * =====================================================================================
 *
 *       Filename:  search_rotated_sorted_array2.cpp
 *
 *    Description:  Follow up for "Search in Rotated Sorted Array":
 *                  What if duplicates are allowed? Write a function to determin
 *                  if a given target is in the array.
 *
 *        Version:  1.0
 *        Created:  03/20/2014 09:18:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
  public:
    bool search(int A[], int n, int target) {
      int lo = 0, hi = n - 1;
      while (lo <= hi) {
        int mid = (lo+hi) / 2;
        if (target == A[mid]) {
          return true;
        }

        if (A[lo] < A[mid]) {
          if (A[lo] <= target && target < A[mid])
            hi = mid - 1;
          else
            lo = mid + 1;
        } else if (A[lo] > A[mid]) {
          if (A[mid] < target && target <= A[hi])
            lo = mid + 1;
          else
            hi = mid - 1;
        } else {
          lo++;
        }

      }
      return false;
    }
};

int
main()
{
  int A[] = {4, 5, 6, 7, 0, 1, 2};
  int B[] = {4, 5, 6, 7, 8, 1, 2, 3};
  int C[] = {5, 1, 3};
  int D[] = {5, 1, 2, 3, 4};
  int n = 7;
  Solution solution;
  assert(solution.search(A, n, 4));
  assert(solution.search(A, n, 5));
  assert(solution.search(A, n, 6));
  assert(solution.search(A, n, 7));
  assert(solution.search(A, n, 0));
  assert(solution.search(A, n, 1));
  assert(solution.search(A, n, 2));
  assert(!solution.search(A, n, 9));
  assert(solution.search(B, 8, 8));
  assert(solution.search(C, 3, 3));
  assert(solution.search(D, 5, 4));
  assert(solution.search(D, 5, 1));
}
