/*
 * =====================================================================================
 *
 *       Filename:  largest_rectangle.cpp
 *
 *    Description:  Given n non-negative intgers representing the histogram's
 *                  bar height where width of each bar is 1, find the area of 
 *                  largest rectangle in the histogram.
 *
 *        Version:  1.0
 *        Created:  03/20/2014 12:49:19 PM
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
#include <assert.h>

using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &height) {
      if (height.empty())
        return 0;
      vector<int> mins(height.size(), 0);
      mins[0] = -1;
      int res = height[0];
      for (int i = 1; i < height.size(); i++) {
        int j;
        for (j = i-1; j != -1 && height[j] >= height[i]; j = mins[j]);
        mins[i] = j;
      }

      for (int i = 1; i < height.size(); i++) {
        int area = height[i]*(i-mins[i]);
        for (int j = mins[i]; j != -1; j = mins[j]) {
          area = max(area, height[j]*(i - mins[j]));
        }
        res = max(area, res);
      }
      return res;
    }
};

int
main()
{
  vector<int> histgram = {2,1,5,6,2,3};
  Solution solution;
  assert(solution.largestRectangleArea(histgram) == 10);
}
