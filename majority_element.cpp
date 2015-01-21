/*
 * =====================================================================================
 *
 *       Filename:  majority_element.cpp
 *
 *    Description:  Given an array of size n, find the majority element. The majority
 *                  element is the element that appears more then [n/2] times.
 *                  You may assume that the array is non empty and the majority element
 *                  always exist in the array.
 *
 *        Version:  1.0
 *        Created:  01/21/2015 10:27:41 PM
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
    int majorityElement(vector<int> &num) {
      sort(num.begin(), num.end());
      int lim = num.size() / 2;
      int begin = 0, last = num[0];

      for (int i = 1; i < num.size(); i++) {
        if (num[i] != last) {
          if ((i - begin) > lim) {
            return last;
          } else {
            begin = i;
            last = num[i];
          }
        }
      }
     return last;
    }
};


int
main(int argc, char *argv[]) {
  Solution s;
  vector<int> data;
  data.push_back(1);
  cout << s.majorityElement(data) << endl;
}
