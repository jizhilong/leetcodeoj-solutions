/*
 * =====================================================================================
 *
 *       Filename:  unique_bsts.cpp
 *
 *    Description:  Given n,how many structually unique BST's that stores 1..n?
 *
 *        Version:  1.0
 *        Created:  03/16/2014 02:32:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int numTrees(int n) {
      if (n <= 0)
        return 0;
      vector<int> dp(n+1, 0);
      dp[0] = dp[1] = 1;

      for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i/2; j++) {
          dp[i] += 2*dp[j]*dp[i-1-j];
        }
        if (i % 2) {
          dp[i] += dp[i/2]*dp[i/2];
        }
      }

      return dp[n];
    }
};

int
main()
{
  Solution solution;
  assert(solution.numTrees(1) == 1);
  assert(solution.numTrees(2) == 2);
  assert(solution.numTrees(3) == 5);
  assert(solution.numTrees(4) == 14);
  assert(solution.numTrees(5) == 42);
}
