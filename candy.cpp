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
#include <algorithm>

using namespace std;
const int U = 0;  /* climing direction: up */
const int D = 1;  /* climing direction: down */

class Solution {
  public:
    int candy_wave(int up, int down) {
      if (up == 0)
        return (down*(down+1))/2;

      if (up >= down) {
        return ((up+3)*up) / 2 + (down*(down+1)) / 2;
      }

      return ((up+2)*(up-1)) / 2 + ((down+2)*(down+1)) / 2;
    }

    int candy(vector<int> &ratings) {
      if (ratings.size() == 0)
        return 0;
      int count[] = {0, 1};
      int dir = D; 
      int last = ratings[0], j;
      int len = ratings.size();
      int total = 0;

      for (int i = 1; i < len; i++) {
        int rt = ratings[i];
        if (rt == last) {
          total += candy_wave(count[U], count[D]);
          count[U] = 0;
          count[D] = 1;
          for (j = i+1; j < len && ratings[j] == rt; j++);
          total += j - i - 1;
          i = j - 1;
          dir = D;
        } else if (rt < last) {
          count[D]++;
          dir = D;
        } else {
          if (dir == D) {
            total += candy_wave(count[U], count[D]);
            dir = U;
            count[U] = 1;
            count[D] = 0;
          } else {
            count[U]++;
          }
        }
        last = rt;
      }
      
      total += candy_wave(count[U], count[D]);
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
