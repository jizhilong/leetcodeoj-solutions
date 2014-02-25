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

class Solution {
  public:
    int num(int should, int count) {
      if (count <= 2)
        return should*count;
      return should*2 + count -2;
    }

    int candy(vector<int> &ratings) {
      vector<vector<int> > updown(2);
      int downing = 1;
      int total = 0;
      int len = ratings.size();
      int start, end;
      for (start = 0; start < len && ratings[start] == ratings[0]; start++);
      --start;
      for (end = len - 1; end >= start && ratings[end] == ratings[len-1]; end--);
      end +=2;
      
      total += start + (len - end);
//      cout << start << endl;
//      cout << end << endl;
//      cout << total << endl;

      for (int i = start; i < end;) {
        int j, rt = ratings[i];
        for (j = i+1; j < end && ratings[j] == rt; j++ ); /* count continueing same ratings */
        updown[downing].push_back(j - i);
        i = j;

        if (j == end || (downing == 1 && ratings[j] > rt)) { /* get to a minimum point or reach the last rating  */
          downing = 0;
          int su = updown[0].size(), sd = updown[1].size();

          for (int m = 0; m < su - 1; m++)
            total += num(m+2, updown[0][m]);
          for (int n = 0; n < sd; n++)
            total += num(sd - n, updown[1][n]);

          if (su > 0) {
            if (updown[0][su-1] == 1)
              total += max(1+su, sd);   /* how many candy should the kid with maximum rating get */
            else
              total += 1+su+sd+(updown[0][su-1]-2);
          }
          cout << "i = " << i << " total = " << total << endl;
          updown[0].clear(); updown[1].clear();
        } else if (downing == 0 && ratings[j] < rt){ /* get to a maximum point */
          downing = 1;
        }
      }

      return total;
    }
};


int
main()
{
  int arr[] = {1, 2, 2, 1};
  vector<int> ratings(arr, arr + sizeof(arr)/sizeof(int));
  Solution solution;
  cout << solution.candy(ratings) << endl;
}