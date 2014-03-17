/*
 * =====================================================================================
 *
 *       Filename:  gray_code.cpp
 *
 *    Description:  The gray code is a binary numeral system where two successive
 *                  values differ only in one bit.Given a non-negative interger
 *                  n representing the total number of bits in the code, print 
 *                  the sequence of gray code.A gray code sequence must begin
 *                  with 0.For example, given n = 2, return [0,1,3,2].
 *
 *        Version:  1.0
 *        Created:  03/17/2014 08:35:37 AM
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
#include <bitset>

using namespace std;

class Solution {
  public:
    vector<int> grayCode(int n) {
      vector<int> res;
      res.push_back(0);

      for (int i = 0; i < n; i++) {
        int mask = 1 << i;
        int count = res.size();
        for (int j = count - 1; j >= 0 ; j--) {
          res.push_back(res[j] | mask);
        }
      }
      return res;
    }
};

int
main()
{
  Solution solution;
  vector<int> res;
  res = solution.grayCode(5);

  for (int i = 0; i < res.size(); i++) {
    cout << bitset<32>(res[i]) << endl;
  }
}
