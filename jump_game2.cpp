/*
 * =====================================================================================
 *
 *       Filename:  jump_game2.cpp
 *
 *    Description:  Given an array of non-negative integers, you are initially 
 *                  positioned at the first index of the array.Each element in 
 *                  the array represents your maximum jump length at that position
 *                  Your goal is to reach the last index in the minimum number
 *                  of jumps.For example:
 *                  Given array A = [2,3,1,1,4]
 *                  The minimum number of jumps to reach the last index is 2.
 *
 *        Version:  1.0
 *        Created:  03/27/2014 08:50:16 PM
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
#include <algorithm>

using namespace std;

class Solution {
  public:
    int jump(int A[], int len) {
      vector<int> dp(len, len);
      dp[len-1] = 0;
      for (int i = len - 1; i >= 0; i--) {
        for (int j = min(len - 1, i+A[i]); j > i; j--) {
          if (dp[j]+1 < dp[i])
            dp[i] = dp[j]+1;
        }
      }
      return dp[0];
    }
};

int
main()
{
  int A[] = {2,3,1,1,4};
  Solution solution;

  cout << solution.jump(A, sizeof(A)/sizeof(int)) << endl;

}
