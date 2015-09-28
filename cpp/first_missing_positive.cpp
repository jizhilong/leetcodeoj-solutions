/*
 * =====================================================================================
 *
 *       Filename:  first_missing_positive.cpp
 *
 *    Description:  Given an unsorted integer array, find the first missing
 *                  possitive integer.
 *                  For example.
 *                  Given [1,2,0] return 3.
 *                  and [3,4,-1,1] return 2.
 *                  Your algorithm should run in O(n) time and use constant space.
 *
 *        Version:  1.0
 *        Created:  03/28/2014 08:18:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int firstMissingPositive(int A[], int n) {
      for (int i = 0; i < n;) {
        if (A[i] <= 0 ||  A[i] > n || A[i] == A[A[i]-1]) {
          i++;
          continue;
        }
        swap(A[i], A[A[i]-1]);
      }
      int ret;
      for (ret = 1; ret <= n && A[ret-1] == ret; ret++);
      return ret;
    }
};

int
main()
{
  int A[] = {1,2,0};
  int B[] = {1,1};
  Solution solution;
  cout << solution.firstMissingPositive(A, sizeof(A)/sizeof(int)) << endl;
  cout << solution.firstMissingPositive(B, sizeof(B)/sizeof(int)) << endl;
}
