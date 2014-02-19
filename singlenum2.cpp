/*
 * =====================================================================================
 *
 *       Filename:  singlenum2.cpp
 *
 *    Description:  Given an array of integers, every element appears three times
 *                  except for one. Find the single one.
 *                  -------------------------------------------------------------
 *                  NOTE: Your algorithm should have a linear runtime complexity.
 *                        Could you implement it without using extra memory?
 *
 *        Version:  1.0
 *        Created:  02/19/2014 11:11:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
      /* a straight version, using map */

      /* 
      map<int, int> dict;
      for (int i = 0; i < n ; i++) {
        if (dict.find(A[i]) == dict.end()) {
          dict[A[i]] = 1;
        } else {
          dict[A[i]] += 1;
        }
      }

      map<int, int>::iterator it;
      for (it = dict.begin(); it->second != 1; it++);
      return it->first;
      */

      /* another version using bit manipulation */
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];    /* bits which has appeared twice */
        ones ^= A[i];           /* bits which has appeared only once */
        threes = ones & twos;   /* bits which has appeared three times */
        ones &= ~threes;        
        twos &= ~threes;
    }

    return ones;
    }
};

int
main(int argc, char *argv[])
{
  int A[] = {1, 1, 1, 3, 3, 3, 0, 0, 0, -1};
  Solution solution;
  cout << solution.singleNumber(A, 10) << endl;
  return 0;
}
