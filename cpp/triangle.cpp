/*
 * =====================================================================================
 *
 *       Filename:  triangle.cpp
 *
 *    Description:  Given a triangle, find the minimum path sum from top to
 *                  bottom. Each step you may move to adjacent numbers on the 
 *                  row below.For example, given the following triangle
 *                  ------------------------------------------------------------
 *                  [
 *                       [2],
 *                       [3,4],
 *                      [6,5,7],
 *                     [4,1,8,3]
 *                   ]
 *                   -----------------------------------------------------------
 *                   the minimum path sum from top to bottom is 11 (i.e, 2+3+5+1
 *
 *        Version:  1.0
 *        Created:  03/13/2014 08:32:39 PM
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
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> dp(triangle.size(), 0);

        for (int i = triangle.size() - 1; i > 0; i--) {
          for (int j = 0; j < i; j++) {
            if (dp[j] + triangle[i][j] < dp[j+1] + triangle[i][j+1])
              dp[j] += triangle[i][j];
            else
              dp[j] = dp[j+1] + triangle[i][j+1];
          }
        }

        return dp[0] + triangle[0][0];
    }
};

int
main(int argc, char *argv[]) {
  vector<vector<int> > triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
  Solution solution;
  cout << solution.minimumTotal(triangle) << endl;
}
