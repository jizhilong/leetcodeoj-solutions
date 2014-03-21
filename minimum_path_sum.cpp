/*
 * =====================================================================================
 *
 *       Filename:  minimum_path_sum.cpp
 *
 *    Description:  Given a m x n grid filled with non-negative numbers, find a
 *                  path from top left to bottom right which minimizes the sum 
 *                  of all numbers along its path.You can only move either down
 *                  or right at any point in time.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 02:04:40 PM
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
    int minPathSum(vector<vector<int> > &grid) {
      if (grid.empty())
        return 0;
      vector<vector<int> > dp(grid.size(), vector<int>(grid[0].size(), 0));
      dp[0][0] = grid[0][0];
      for (int i = 1; i < grid[0].size(); i++)
        dp[0][i] = grid[0][i] + dp[0][i-1];
      for (int i = 1; i < grid.size(); i++)
        dp[i][0] = grid[i][0] + dp[i-1][0];

      for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[i].size(); j++) {
          dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
        }
      }

      return dp.back().back();

    }
};

int
main()
{
  vector<vector<int> > grid = {{1,1,1}, {2,1,3},{0,0,0}};
  Solution solution;
  cout << solution.minPathSum(grid) << endl;
}
