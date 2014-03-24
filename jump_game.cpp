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
#include <queue>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
  public:
    bool canJump(int A[], int n) {
      if (n <= 1)
        return true;
      queue<int> q;
      vector<bool> mark(n, false);
      q.push(n-1);
      mark[n-1] = true;

      while (!q.empty()) {
        int i = q.front(); q.pop();

        if (i == 0) {
          return true;
        }

        for (int j = i-1; j >= 0; j--) {
          if (j+A[j] >= i && !mark[j]) {
            mark[j] = true;
            q.push(j);
          }
        }
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
