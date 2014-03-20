/*
 * =====================================================================================
 *
 *       Filename:  search_rotated_sorted_array.cpp
 *
 *    Description:  Suppose a sorted array is rotated at some pivot unknown to 
 *                  you beforehand.You are given a target value to search.If you
 *                  found in the array return its index, otherwise return -1.You
 *                  may assume no duplicate exists in the array.
 *
 *        Version:  1.0
 *        Created:  03/20/2014 04:12:40 PM
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
    int search(int A[], int n, int target) {
      int lo = 0, hi = n - 1;
      while (lo <= hi) {
        int mid = (lo+hi) / 2;
        if (target == A[mid]) {
          return mid;
        }

        if (A[lo] < A[mid]) {
           if (A[lo] <= target && target < A[mid]){ // left part sorted
            hi = mid - 1;
          } else {
            lo = mid + 1;
          }
        } else if (A[lo] > A[mid]){
          if (A[mid] < target && target <= A[hi]){ // right part sorted
            lo = mid + 1;
          } else {
            hi = mid - 1;
          }
        } else {
          lo++;
        }
      }
      return -1;
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
  assert(solution.search(A, n, 4) == 0);
  assert(solution.search(A, n, 5) == 1);
  assert(solution.search(A, n, 6) == 2);
  assert(solution.search(A, n, 7) == 3);
  assert(solution.search(A, n, 0) == 4);
  assert(solution.search(A, n, 1) == 5);
  assert(solution.search(A, n, 2) == 6);
  assert(solution.search(A, n, 9) == -1);
  assert(solution.search(B, 8, 8) == 4);
  assert(solution.search(C, 3, 3) == 2);
  assert(solution.search(D, 5, 4) == 4);
  assert(solution.search(D, 5, 1) == 1);
}
