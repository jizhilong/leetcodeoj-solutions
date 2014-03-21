/*
 * =====================================================================================
 *
 *       Filename:  search_insert_position.cpp
 *
 *    Description:  Given a sorted array and a target value, return the index if
 *                  the target is found.If not, return the index where it would
 *                  be if it were inserted in order.You may assume no duplicates
 *                  in the array.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 08:27:17 AM
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
    int searchInsert(int A[], int n, int target) {
      int i;
      for (i = 0; i < n && A[i] < target; i++);
      return i;
    }
};

int
main() {
  int A[] = {1,3,5,6};
  int n = 4;
  Solution solution;

  assert(solution.searchInsert(A, n, 5) == 2);
  assert(solution.searchInsert(A, n, 2) == 1);
  assert(solution.searchInsert(A, n, 7) == 4);
  assert(solution.searchInsert(A, n, 0) == 0);
}
