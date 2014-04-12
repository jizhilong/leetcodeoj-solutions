/*
 * =====================================================================================
 *
 *       Filename:  median_of_sorted_arrays.cpp
 *
 *    Description:  There are two sorted arrays A and B of size m and n.
 *                  Find the median of two sorted array.
 *
 *        Version:  1.0
 *        Created:  04/12/2014 11:28:27 PM
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

int bsearch(int *A, int n, int t) {
  int lo = 0, hi = n-1;
  while (lo <= hi) {
    int mid = (lo+hi) / 2;
    if (A[mid] == t) {
      return mid;
    } else if (A[mid] < t) {
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }

  return lo;
}

int findKth(int *A, int m, int *B, int n, int k) {
  if (m == 0)
    return B[k];
  if (n == 0)
    return A[k];

  if (A[0] == B[0]) {
    if (k <= 1)
      return A[0];
    else
      return findKth(A+1, m-1, B+1, n-1, k-2);
  }

  if (A[m-1] <= B[0]) { /* [A1,A2...Am,B1,B2...Bn] */
    if (k < m)
      return A[k];
    else
      return B[k-m];
  }

  if (B[n-1] <= A[0]) { /* [B1,B2...Bn,A1,A2...Am] */
    if (k < n)
      return B[k];
    else
      return A[k-n];
  }

  if (B[0] >= A[0]) {  /* [A1,A2..A[h-1]...B1....Am..Bn] */
    int h = bsearch(A, m, B[0]);
    if (h > k || (h==k && A[h] == B[0]))
      return A[k];
    return findKth(A+h, m-h, B, n, k-h);
  } else {
    int h = bsearch(B, n, A[0]);
    if (h > k || (h==k && B[h] == A[0]))
      return B[k];
    return findKth(A, m, B+h, n-h, k-h);
  }
}

class Solution {
  public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
      int a = findKth(&A[0], m, &B[0], n, (m+n)/2);
      if ((m+n) % 2 == 1)
        return a;
      int b = findKth(&A[0], m, &B[0], n, (m+n)/2-1);
      return (double)(a+b) / 2.0;
    }
};

int
main()
{
  int A[] = {1,3,5,6,7};  /* 1,2,3,4,5,5,6,7,9,10 */
  int B[] = {2,4,5,9,10};
  Solution solution;
  cout << solution.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)) << endl;
}

