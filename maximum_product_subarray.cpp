/*
 * =====================================================================================
 *
 *       Filename:  maximum_product_subarray.cpp
 *
 *    Description:  Find the contiguous subarray within an array(containing at least one
 *                  number)which has the largest product.
 *                  For example, given the array [2, 3, -2, 4],
 *                  the contiguous subarray [2, 3] has the largest product = 6.
 *
 *        Version:  1.0
 *        Created:  01/30/2015 12:42:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;


class Solution {
  public:
    int maxProduct(int A[], int n) {
      int max, maxe, min, mine;
      int tmaxe;
      max = maxe = A[0];
      min = mine = A[0];

      for (int i = 1; i < n; i++) {
        if (A[i] > 0) {
          if (maxe > 0) {
            maxe *= A[i];
          } else {
            maxe = A[i];
          }

          if (mine <= 0) {
            mine *= A[i];
          } else {
            mine = A[i];
          }
        } else if (A[i] < 0) {
          tmaxe = maxe;
          if (maxe <= 0) {
            maxe = mine * A[i];
          } else {
            maxe = A[i] > A[i]*mine ? A[i] : A[i]*mine;
          }
          if (mine > 0) {
            mine = tmaxe * A[i];
          } else {
            mine = A[i] < A[i]*tmaxe ? A[i] : A[i]*tmaxe;
          }
        } else {
          maxe = mine = 0;
        }

        max = max > maxe ? max : maxe;
        min = min < mine ? min : mine;
      }
      return max;
    }
};


int
main(int argc, char *argv[])
{
  int anums[] = {-4, -3, -2};

  Solution s;
  cout << s.maxProduct(anums, 3) << endl;
}
