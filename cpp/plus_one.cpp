/*
 * =====================================================================================
 *
 *       Filename:  plus_one.cpp
 *
 *    Description:  Given a non-negative number represented as an array of digit
 *                  plus one to the number.The digits are stored such that the 
 *                  most significant digit is at the head of the list.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 02:30:59 PM
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
    vector<int> plusOne(vector<int> &digits) {
      vector<int> res(digits.begin(), digits.end());
      if (res.empty())
        return res;
      int len = res.size();
      int inc, i;
      for (inc = 1, i = len - 1; i >= 0 && inc; i--) {
        inc += res[i];
        res[i] = inc % 10;
        inc /= 10;
      }
      if (inc) 
        res.insert(res.begin(), inc);
      return res;
    }
};

int
main()
{
  vector<int> num = {9,9,9,9};
  vector<int> res;
  Solution solution;
  res = solution.plusOne(num);
  for (int i = 0; i < res.size(); i++)
    cout << res[i];
  cout << endl;
}
