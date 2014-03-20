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
      int len = height.size();
      if (len == 0)
        return 0;
      vector<int> minsl(height.size(), 0);
      vector<int> minsr(height.size(), 0);
      minsl[0] = -1;
      minsr[height.size() - 1] = height.size();

      int res = height[0];

      for (int i = 1; i < len; i++) {
        int j;
        for (j = i-1; j != -1 && height[j] >= height[i]; j = minsl[j]); /* which is the first left lower bar*/
        minsl[i] = j;
        for (j = len - i; j != len && height[j] >= height[len-1-i]; j = minsr[j]);  /* which is the first right lower bar */
        minsr[len - i - 1] = j;
      }

      for (int i = 1; i < len; i++) {
        res = max(res, height[i]*(minsr[i]-minsl[i] - 1)); /* what is the area with the current bar as the rectangle height */
      }
      return res;
    }
};

int
main()
{
  vector<int> histgram;
  int tmp;
  while (cin >> tmp) {
    histgram.push_back(tmp);
  }
  Solution solution;
  cout << solution.largestRectangleArea(histgram) << endl;
}
