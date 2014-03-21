/*
 * =====================================================================================
 *
 *       Filename:  unique_paths.cpp
 *
 *    Description:  A robot is located at the top left corner of a m x n grid 
 *                  The robot can only move either down or right at any point
 *                  in time.The robot is trying to reach the bottom right corner
 *                  how many possible unique paths are there?
 *
 *        Version:  1.0
 *        Created:  03/21/2014 02:19:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
      if (m*n == 0)
        return 0;
      vector<vector<int> > dp(m, vector<int>(n, 1));

      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
      }

      return dp.back().back();

    }
};

int
main()
{
  Solution solution;
  assert(solution.uniquePaths(1,1) == 1);
  assert(solution.uniquePaths(0,1) == 0);
  assert(solution.uniquePaths(2,2) == 2);
}
