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
const int U = 0;  /* climing direction: up */
const int D = 1;  /* climing direction: down */

class Solution {
  public:
    int candy_wave(int *count) {
      int up = count[U], down = count[D];
      count[U] = count[D] = 0;

      if (up == 0)
        return (down*(down+1))/2;

      if (up >= down) {
        return ((up+3)*up) / 2 + (down*(down+1)) / 2;
      }

      return ((up+2)*(up-1)) / 2 + ((down+2)*(down+1)) / 2;
    }

    int candy(vector<int> &ratings) {
      int len = ratings.size();
      int count[] = {0, 1};
      int total = 0;

      if (len == 0)
        return 0;

      for (int i = 1, last = ratings[0], dir = D; i < len; last = ratings[i++], count[dir]++) {
        if (ratings[i] == last) {             /* meet a same rating, split the line into two */
          total += candy_wave(count); 
          dir = D;
        } else if (ratings[i] < last) {       /* going down */
          dir = D;                    
        } else if (dir == D) {        /* meet a local minimum */
            total += candy_wave(count);
            dir = U;
        } 
      }
      
      total += candy_wave(count);
      return total;
    }
};


int
main()
{
  int arr[] = {1, 3, 5};
  vector<int> ratings(arr, arr + sizeof(arr)/sizeof(int));
  Solution solution;
  cout << solution.candy(ratings) << endl;
}
