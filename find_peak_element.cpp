/*
 * =====================================================================================
 *
 *       Filename:  find_peak_element.cpp
 *
 *    Description:  A peak element is an element that is greater than its neighbors.
 *                  Given an input array where num[i] != num[i+1], find a peak element
 *                  and return its index.The array may contain multiple peaks, in that
 *                  case return the index of any one of the peaks is fine.
 *                  You can imagine that num[-1] = num[n] = -∞.
 *                  For example, in array [1,2,3,1], 3 is a peak element your function
 *                  should return the index number 2.
 *                  NOTE: your solution should be logarithmic complexity.
 *
 *        Version:  1.0
 *        Created:  01/29/2015 11:57:01 PM
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

using namespace std;

class Solution {
  public:
    int findPeakElement(const vector<int> &num) {
      int i = 0, j = num.size() - 1;
      while (i < j) {
        if (num[i] > num[i+1])
          return i;
        if (num[j] > num[j-1])
          return j;
        i++;
        j--;
      }
      return i;
    }
};


int
main(int argc, char *argv[])
{
  int anums[] = {1, 2, 3, 1};
  vector<int> vnums = vector<int>(anums, anums + sizeof(anums)/sizeof(int));
  Solution s;
  cout << s.findPeakElement(vnums) << endl;
}
