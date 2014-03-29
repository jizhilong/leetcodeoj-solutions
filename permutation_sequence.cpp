/*
 * =====================================================================================
 *
 *       Filename:  permutation_sequence.cpp
 *
 *    Description:  The set [1,2,3...n] contains a total of n! unique permutations
 *                  By listing and labeling all of the permutations in order. We
 *                  get the following sequence (ie,for n = 3):
 *                  1."123",2."132",3."213",4."231",5."312",6."321"
 *                  Given n and k, return the kth permutation sequence.
 *                  Note: Given n will be between 1 and 9 inclusive.
 *
 *        Version:  1.0
 *        Created:  03/29/2014 07:46:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Solution {
  private:
    void getPermutation(string &str, int s, int k) {
      if (k <= 1)
        return;

      int j = 2;
      int acc = 1;
      while (acc < k) {
        acc = acc*(j++);
      }
      j--;
      acc /= j;
      int no_change = str.length() - j; /* str[s:no_change] keep unmodified */
      int n = (k+acc-1) / acc;          /* str[no_change] = str[no_change+n-1] */
      for (int i = no_change+n-1; i > no_change; i--)
        swap(str[i], str[i-1]);
      getPermutation(str, no_change, k - acc*(n-1));
    }

  public:
    string getPermutation(int n, int k) {
      stringstream ss;
      for (int i = 1; i <= n; i++)
        ss << i;
      string ret = ss.str();
      getPermutation(ret, 0, k);
      return ret;
    }
};

int
main(int argc, char *argv[])
{
  Solution solution;
  cout << solution.getPermutation(atoi(argv[1]), atoi(argv[2])) << endl;
}
