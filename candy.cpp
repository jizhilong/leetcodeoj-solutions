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
      /* how many candies at least should be prepared for a ratings peak,
       * with count[0] as the number of kids on the left(upward) side 
       * of the peak, and count[1] as the number of kids on the right(downward)
       * side of the peak.
       */
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
      int count[] = {0, 1}; /* count of ratings on both sides of a peak */
      int total = 0;

      if (len == 0)
        return 0;

      for (int i = 1, last = ratings[0], dir = D; /* assuming we are going down initially */
           i < len; 
           last = ratings[i++], count[dir]++) {   /* add the new kid to the right side of the current peak */
        if (ratings[i] == last) {                 /* meet a same rating, split the line into two */
          total += candy_wave(count);             /* count the last peak's minimum candies required */
          dir = D;                                /* as if we are on at the begining of new line */
        } else if (ratings[i] < last) {           /* going down along the current peak */
          dir = D;                    
        } else if (dir == D) {                    /* a direction turn from downward to upward means the last point is a local minium*/
            total += candy_wave(count);           /* count the last peak */
            dir = U;                              /* and add the current kid to a new peak's upward side */
        } 
      }
      
      total += candy_wave(count);                 /* count the last peak */
      return total;
    }
};


int
main()
{
  int arr[] = {1, 3, 5, 7};
  vector<int> ratings(arr, arr + sizeof(arr)/sizeof(int));
  Solution solution;
  cout << solution.candy(ratings) << endl;
}
