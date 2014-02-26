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
    int candy(vector<int> &ratings) {
      int len = ratings.size(); 
      int count[] = {0, 1}; /* count of ratings on both sides of a peak */
      int total = 1, i, last, dir;

      if (len == 0)
        return 0;

#define COUNT_WAVE() total += (count[U] && count[D] > count[U]) ? count[D] : count[U]; count[U] = count[D] = 0

      for (i = 1, last = ratings[0], dir = D; /* assuming we are going down initially */
           i < len; 
           last = ratings[i++], total += ++count[dir]) {   /* add the new kid to the right side of the current peak */
        if (ratings[i] == last) {                 /* meet a same rating, split the line into two */
          COUNT_WAVE();
          dir = D;                                /* as if we are on at the begining of new line */
        } else if (ratings[i] < last) {           /* going down along the current peak */
          dir = D;                    
        } else if (dir == D) {                    /* a direction turn from downward to upward means the last point is a local minium*/
            COUNT_WAVE();
            dir = U;                              /* and add the current kid to a new peak's upward side */
        }
      }
      
      COUNT_WAVE();
      return total;
    }
};


int
main()
{
  int arr[] = {1, 3, 2, 2};
  vector<int> ratings(arr, arr + sizeof(arr)/sizeof(int));
  Solution solution;
  cout << solution.candy(ratings) << endl;
}
