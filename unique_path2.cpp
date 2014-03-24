/*
 * =====================================================================================
 *
 *       Filename:  unique_path2.cpp
 *
 *    Description:  Follow up "Unique Paths".Now consider if some obstacles are
 *                  added to the grids.How many unique paths would there be?
 *                  An obstacle and empty space is marked as 1 and 0.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 08:24:03 PM
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

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int> > &grid) {
      vector<vector<int> > dp = grid;
      if (dp.empty())
        return 0;

      dp[0][0] = grid[0][0] == 1 ? 0 : 1;

      for (int i = 1; i < grid.size(); i++) {
        dp[i][0] = grid[i][0] == 1 ? 0 : dp[i-1][0];
      }

      for (int j = 1; j < grid[0].size(); j++) {
        dp[0][j] = grid[0][j] == 1 ? 0 : dp[0][j-1];
      }

      for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[i].size(); j++) {
           dp[i][j] = grid[i][j] == 1 ? 0: dp[i-1][j] + dp[i][j-1];
        }
      }

      return dp.back().back();
    }
};

int
main() {
  vector<vector<int> > grid = {{1,0}};
  Solution solution;
  cout << solution.uniquePathsWithObstacles(grid) << endl;
}
