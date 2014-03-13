/*
 * =====================================================================================
 *
 *       Filename:  buy_sell_stock3.cpp
 *
 *    Description:  Say you have an array for which the ith element is the price
 *                  of a given stock on day i. Design an algorithm to find the 
 *                  maximum profit. You may complete at most two transactions. 
 *
 *        Version:  1.0
 *        Created:  03/12/2014 08:54:37 PM
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
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() < 2)
        return 0;
      vector<int> candidates(prices.size(), 0);
      int resl = 0, resr = 0, result = 0;
      int low = prices[0];
      int high = prices[0];

      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < low) {
          low = prices[i];
        } else {
          resl = max(resl, prices[i] - low);
        }
        candidates[i] += resl;
      }

      for (int i = prices.size() -1 ;i >= 0; i--) {
        if (prices[i] > high) {
          high = prices[i];
        } else {
          resr = max(resr, high - prices[i]);
        }
        candidates[i] += resr;
        if (candidates[i] > result)
          result = candidates[i];
      }

      return result;
    }
};

int
main(int argc, char *argv[]) {
  vector<int> arr = {8,3,6,2,8,8,8,4,2,0,7,2,9,4,9};
  Solution solution;
  cout << solution.maxProfit(arr) << endl;
}
