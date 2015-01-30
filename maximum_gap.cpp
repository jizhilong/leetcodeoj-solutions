/*
 * =====================================================================================
 *
 *       Filename:  maximum_gap.cpp
 *
 *    Description:  Given an unsorted array, find the maximum difference between                    the successive elements in its sorted form.
 *                  Try to solve if in linear time/space.
 *                  Return 0 if the array contains less than 2 elements.
 *                  You may assume all elements in the array are non-negative
 *                  and fit in the 32-bit signed integer range.
 *
 *        Version:  1.0
 *        Created:  01/30/2015 09:04:41 PM
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
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maximumGap(vector<int> &num) {
    if (num.size() < 2)
      return 0;
    sort(num.begin(), num.end());
    int gap = num[1] - num[0];
    for (int i = 2; i < num.size(); i++) {
      int tgap = num[i] - num[i-1];
      gap = tgap > gap ? tgap : gap;
    }

    return gap;
  }
};


int
main(int argc, char *argv[]) {

}
