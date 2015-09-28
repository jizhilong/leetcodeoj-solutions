/*
 * =====================================================================================
 *
 *       Filename:  remove_dup_array.cpp
 *
 *    Description:  Given a sorted array, remove the duplicates in place
 *                  such that each element appear only once and return the 
 *                  new length.
 *
 *        Version:  1.0
 *        Created:  03/20/2014 09:52:24 PM
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
    int removeDuplicates(int A[], int n) {
      int len = 0;
      for (int i = 0; i < n;) {
        A[len]= A[i];
        for (i = i + 1;i < n && A[i] == A[len]; i++);
        len++;
      }
      return len;
    }
};

int
main()
{
  int A[] = {1,1,2};
  Solution solution;
  int newlen = solution.removeDuplicates(A, 3);
  for (int i= 0; i < newlen; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
