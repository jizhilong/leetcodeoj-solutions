/*
 * =====================================================================================
 *
 *       Filename:  merge_array.cpp
 *
 *    Description:  Given two sorted integer arrays A and B, merge B into A as 
 *                  one sorted array.You may assume that A has enough space to 
 *                  hold additional elements from B.
 *
 *        Version:  1.0
 *        Created:  03/17/2014 08:12:38 PM
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
    void merge(int A[], int m, int B[], int n) {
      int i = m - 1, j = n - 1, k = m + n - 1;
      while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
          A[k--] = A[i--];
        } else {
          A[k--] = B[j--];
        }
      }

      while (i >= 0)
        A[k--] = A[i--];

      while (j >= 0)
        A[k--] = B[j--];
    }
};

int
main()
{
  int A[] = {1,2,3,0,0,0};
  int B[] = {-1,4,5};
  Solution solution;
  solution.merge(A, 3, B, 3);

  for (int i = 0; i < 6; i++)
    cout << A[i] << " ";
  cout << endl;
}
