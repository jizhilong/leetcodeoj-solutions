/*
 * =====================================================================================
 *
 *       Filename:  climbing_stairs.cpp
 *
 *    Description:  You are climing a stair case.It takes n steps to reach to 
 *                  the top.Each time you can either clim 1 or 2 steps. In how
 *                  many ways can you climb to the top.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 08:38:14 AM
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

using namespace std;

class Solution {
  public:
    int climbStairs(int n) { /* this is fibonacci actually */
      int pre = 1, next = 1;
      for (int i = 0; i < n; i++) {
        next = next + pre;
        pre = next - pre;
      }
      return pre;
    }
};

int
main()
{
  Solution solution;

  assert(solution.climbStairs(0) == 1);
  assert(solution.climbStairs(1) == 1);
  assert(solution.climbStairs(2) == 2);
  assert(solution.climbStairs(3) == 3);
}
