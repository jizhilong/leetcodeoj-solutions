/*
 * =====================================================================================
 *
 *       Filename:  candy.cpp
 *
 *    Description:  There are N children standing in a line. Each child assigned a rating
 *                  value.You are giving  candies to these children subjected to the 
 *                  following requirements:
 *                  --------------------------------------------------------------------
 *                  - Each child must have at least one candy.
 *                  - Children with a higher rating get more candies than their neighbors.
 *                  --------------------------------------------------------------------
 *                  What is the minimum candies you must give.
 *
 *        Version:  1.0
 *        Created:  02/24/2014 10:43:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmial.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int candy(vector<int> &ratings) {
      return 0;
    }
};


int
main()
{
  int arr[] = {1, 2, 1, 4, 3, 5, 2, 7, 8, 1};
  vector<int> ratings(arr, arr + sizeof(arr)/sizeof(int));
  Solution solution;
  cout << solution.candy(ratings) << endl;
}
