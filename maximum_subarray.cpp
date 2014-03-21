/*
 * =====================================================================================
 *
 *       Filename:  maximum_subarray.cpp
 *
 *    Description:  Find the contiguous subarray within an array (containing at
 *                  least one number) which has the largest sum.
 *                  For example, given the array [-2,1,-3,4,-1,2,1,-5,4].The 
 *                  contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 09:09:11 AM
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
    int maxSubArray(int A[], int n) {
      int max , maxe;
      max = maxe = A[0];
      for (int i = 1; i < n; i++) {
        if (maxe > 0) {
          maxe += A[i];
        } else {
          maxe = A[i];
        }
        max = max > maxe ? max : maxe;
      }
      return max;
    }
};


int
main()
{
  int A[] = {-2,1,-3,4,-1,2,1,-5,4};
  Solution solution;
  assert(solution.maxSubArray(A, 9) == 6);
}
