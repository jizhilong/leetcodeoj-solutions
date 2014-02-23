/*
 * =====================================================================================
 *
 *       Filename:  remove_element.cpp
 *
 *    Description:  Given an array and a value, remove all instances of that 
 *                  value in place and return the new length. The order of 
 *                  elements can be changed. It doesn't matter what you leave
 *                  beyond the new length.
 *
 *        Version:  1.0
 *        Created:  02/23/2014 02:33:18 PM
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
    int removeElement(int A[], int n, int elem) {
      int j = 0;
      for (int i = 0; i < n; i++) {
        if (A[i] != elem) {
          if (i != j)
            A[j] = A[i];
          j++;
        }
      }
      return j;
    }
};

int
main()
{
  int A[] = {1,2,3,4,5,6,1,1};
  Solution solution;
  int i = solution.removeElement(A, 8, 1);
  for (int k = 0; k < i; k++)
    cout << A[k] << endl;
}
