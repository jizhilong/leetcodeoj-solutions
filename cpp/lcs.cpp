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
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    if (num.size() <= 1)
      return num.size();

    unordered_set<int> set;
    int res = 0;

    for (auto it = num.begin(); it != num.end(); it++) {
      set.insert(*it);
    }

    for (auto it = set.begin(); it != set.end(); it++) {
      int count = 0, i = 0;
      for (; set.find(*it - i) != set.end();set.erase(i), i++, count++);
      for (i = 1; set.find(*it + i) != set.end();set.erase(i), i++, count++);
      if (count > res)
        res = count;
    }

    return res;
  }
};

int
main(int argc, char *argv[]) 
{
  vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
  Solution solution;

  cout << solution.longestConsecutive(nums) << endl;

}
