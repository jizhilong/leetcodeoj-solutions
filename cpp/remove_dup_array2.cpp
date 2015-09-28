/*
 * =====================================================================================
 *
 *       Filename:  remove_dup_array2.cpp
 *
 *    Description:  Follow up for "Remove Duplicates".
 *                  What if duplicates are allowed at most
 *                  twice?
 *
 *        Version:  1.0
 *        Created:  03/20/2014 09:59:46 PM
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
        A[len++]= A[i];
        int j = i + 1;
        for (;j < n && A[j] == A[i]; j++);
        if (j - i > 1)
          A[len++] = A[i];
        i = j;
      }
      return len;
    }
};

int
main()
{
  int A[] = {1,1,1,1,3,3};
  Solution solution;
  int newlen = solution.removeDuplicates(A, 6);
  for (int i= 0; i < newlen; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
