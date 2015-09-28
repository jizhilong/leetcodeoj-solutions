/*
 * =====================================================================================
 *
 *       Filename:  find_minimum_in_rotated_sorted_array.cpp
 *
 *    Description:  Suppose a sorted array is rotated at some pivot unknown to
 *                  you beforehand.
 *                  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2)
 *                  Find the minimum element.
 *                  You may assume no duplicate exists in the array.
 *
 *        Version:  1.0
 *        Created:  01/30/2015 12:25:52 AM
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
    int findMin(vector<int> &num){
      int i = 0, j = num.size() - 1;
      while (i < j) {
        if (num[i] < num[j])
          return num[i];
        int m = i + ((j - i) >> 1);
        if (num[m] >= num[i]) {
          i = m + 1;
        } else {
          j = m;
        }
      }
      return num[i];
    }
};

int
main(int argc, char *argv[])
{
  int anums[] = {0, 1, 1};
  vector<int> vnums = vector<int>(anums, anums+sizeof(anums)/sizeof(int));

  Solution s;
  cout << s.findMin(vnums) << endl;
}
