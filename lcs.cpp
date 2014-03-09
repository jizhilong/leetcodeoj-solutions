/*
 * =====================================================================================
 *
 *       Filename:  lcs.cpp
 *
 *    Description:   Given an unsorted array of integers, find the length of the longest 
 *                   consecutive elements sequence.
 *                   For example,
 *                      Given [100, 4, 200, 1, 3, 2],
 *                      The longest consecutive elements sequence is [1, 2, 3, 4]. Return 
 *                      its length: 4.
 *                      Your algorithm should run in O(n) complexity. 
 *
 *        Version:  1.0
 *        Created:  03/09/2014 02:38:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    if (num.size() <= 1)
      return num.size();

    sort(num.begin(), num.end());
    int res = 0;
    int tmp = 1;
    int last = num[0];

    for (int i = 1; i < num.size(); last = num[i++]) {
      switch (num[i] - last) {
        case 0:
          break;
        case 1:
          tmp++;
          break;
        default:
          if (tmp > res)
            res = tmp;
          tmp = 1;
      }
    }

    return res;
  }
};

int
main(int argc, char *argv[]) 
{
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  Solution solution;

  cout << solution.longestConsecutive(nums) << endl;

}
