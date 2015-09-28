/*
 * =====================================================================================
 *
 *       Filename:  buy_sell_stock.cpp
 *
 *    Description:  Say you have an array for which the ith element is the price
 *                  of a given stock on day i.If you were only permited to 
 *                  complete at most one transaction (ie, buy one and sell one 
 *                  share of the stock), design an algorithm to find the maximum
 *                  profit.
 *
 *        Version:  1.0
 *        Created:  03/12/2014 08:04:40 PM
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

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      if (prices.empty())
        return 0;
      int res = 0;
      int low = prices[0];

      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < low) {
          low = prices[i];
        } else {
          res = max(res, prices[i] - low);
        }
      }

      return res;
    }
};

int
main(int argc, char *argv[]) {
  vector<int> arr = {1,1,1,1,1};
  Solution solution;
  cout << solution.maxProfit(arr) << endl;
}
