/*
 * =====================================================================================
 *
 *       Filename:  buy_sell_stock2.cpp
 *
 *    Description:  Say you have an array for which the ith element is the price
 *                  of a given stock on day i.Design an algorithm to find the 
 *                  maximum profit.You may complete as many transactions as you
 *                  like(ie, buy one and sell one share of the stock multiple 
 *                  times).However, you may not engage in multiple transactions
 *                  at the same time (ie, you must sell the stock before you buy
 *                  again).
 *
 *        Version:  1.0
 *        Created:  03/12/2014 08:17:05 PM
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

      for (int i = 0; i < prices.size() - 1; i++) {
        if (prices[i+1] > prices[i]) res += prices[i+1] - prices[i];
      }

      return res;
    }
};

int
main(int argc, char *argv[]) {
  vector<int> arr = {1,2,1,2,3};
  Solution solution;
  cout << solution.maxProfit(arr) << endl;
}
