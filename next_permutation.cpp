/*
 * =====================================================================================
 *
 *       Filename:  next_permutation.cpp
 *
 *    Description:  Implement next permutaion, which rearranges numbers into the
 *                  lexicographically next greater permutations of numbers.
 *                  If such arrangement is not possible, it must rearrange it as
 *                  the lowest possible order (ie, sorted in ascending order).
 *                  The replacement must be in-place, do not allocate extra 
 *                  memory.Here are some examples.Inputs are in the left hand 
 *                  column and its corresponding outpus are in the right hand.
 *                  1,2,3 -> 1,3,2
 *                  3,2,1 -> 1,2,3
 *                  1,1,5 -> 1,5,1
 *
 *        Version:  1.0
 *        Created:  03/25/2014 10:42:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &num) {
      if (num.empty()) {
        return;
      }

      int len = num.size();
      int i  = len - 2;
      for (; i >= 0 && num[i] >= num[i+1]; i--);

      if (i == -1) {
        sort(num.begin(), num.end());
      } else {
        int j;
        for (j = len - 1; j > i && num[j] <= num[i]; j--);
        swap(num[i], num[j]);
        sort(num.begin() + i + 1, num.end());
      }
    }
};

int
main()
{
  vector<int> num = {2,3,1};
  Solution solution;
  solution.nextPermutation(num);
  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << " ";
  }
  cout << endl;
}
