/*
 * =====================================================================================
 *
 *       Filename:  container_most_water.cpp
 *
 *    Description:  Given n non-negative integers a1,a2,...,an,where each represents
 *                  a point at coodrnate (i, ai). n vertical lines are drawd 
 *                  such that the two endpoints of line i is at (i, ai) and (i,0)
 *                  Find two lines, which together with x-axis forms a container
 *                  such that the container contains the most water.
 *
 *        Version:  1.0
 *        Created:  03/23/2014 09:52:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
      if (height.size() <= 1)
        return 0;
      vector<int> maxl(height.size(), 0);

      for (int i = 1; i < height.size(); i++) {
        int j;
        for (j = 0; j != i && height[j] < height[i]; j++);
        maxl[i] = j;
      }

      int res = 0;
      for (int i = 0; i < height.size(); i++) {
         res = max(res, (i - maxl[i])*height[i]);
      }

      return res;
    }
};


int
main()
{
  vector<int> height = {2,1};
  Solution solution;
  assert(solution.maxArea(height) == 1);
}
