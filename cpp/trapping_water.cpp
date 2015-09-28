/*
 * =====================================================================================
 *
 *       Filename:  trapping_water.cpp
 *
 *    Description:  Given n non-negative integers representing an elevation map
 *                  where the width of each bar is 1, compute how much water it
 *                  is able to trap after raining.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 10:59:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int trap(int A[], int n) {
      if (n <= 2)
        return 0;
      int res = 0;
      vector<int> maxr(n, A[n-1]);
      vector<int> maxl(n, A[0]);

      for (int i = 1; i < n; i++) {
        maxl[i] = max(A[i], maxl[i-1]);
      }

      for (int i = n-2; i >= 0; i--) {
        maxr[i] = max(A[i], maxr[i+1]);
      }
      
      for (int i = 0; i < n; i++) {
        res += min(maxl[i], maxr[i]) - A[i];
      }
      return res;
    }
};

int
main()
{
  int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  int height1[] = {4,9,4,5,3,2};
  int height2[] = {2,1,0,2};
  int height3[] = {0,7,1,4,6};
  Solution solution;
  cout << solution.trap(height, sizeof(height)/sizeof(int)) << endl;
  cout << solution.trap(height1, sizeof(height1)/sizeof(int)) << endl;
  cout << solution.trap(height2, sizeof(height2)/sizeof(int)) << endl;
  cout << solution.trap(height3, sizeof(height3)/sizeof(int)) << endl;
}
