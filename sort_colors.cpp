/*
 * =====================================================================================
 *
 *       Filename:  sort_colors.cpp
 *
 *    Description:  given an array with n objects colored red, white or blue, 
 *                  sort them so that objects of the same color are adjacent,
 *                  with the colors in the order red, white and blue.Here, we 
 *                  will use the integers 0,1, and 2 to represent the color red
 *                  white and blue respectively.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 12:22:38 PM
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
    void sortColors(int A[], int n) {
      int colors[] = {0,0,0};
      for (int i = 0; i < n; i++) {
        colors[A[i]]++;
      }
      int i = 0;
      for (int k = 0; k < 3; k++) {
        while (colors[k]) {
          A[i++] = k;
          colors[k]--;
        }
      }
    }
};

int
main() {
  int A[] = {0,2,1,1,2,1,1,1};
  int n = 8;
  Solution solution;
  solution.sortColors(A, n);
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
