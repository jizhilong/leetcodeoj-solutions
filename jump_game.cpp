/*
 * =====================================================================================
 *
 *       Filename:  jump_game.cpp
 *
 *    Description:  Given an array of non-negative integers, you are initially
 *                  positioned at the first index of the array.Each element in
 *                  the array represents your maximum jump length at that 
 *                  position.Determin if you are able to reach the last index.
 *                  For example:
 *                  A = [2,3,1,1,4], return true.
 *                  A = [3,2,1,0,4], return false.
 *
 *        Version:  1.0
 *        Created:  03/24/2014 07:44:13 PM
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
    bool canJump(int A[], int n) {
      int canReach = 0;
      for (int i = 0; i < n && i <= canReach; i++) {
        if (i+A[i] > canReach) canReach = i+ A[i];
        if (canReach >= n-1) return true;
      }
      return false;
    }
};

int
main() {
  int A[] = {2,3,1,1,4};
  Solution solution;
  assert(solution.canJump(A, sizeof(A)/sizeof(int)));
}
