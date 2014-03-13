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

struct Trans {
  int buy;
  int sell;
  int prof;

  Trans(int x, int y):buy(x), sell(y), prof(sell-buy) {};
};

class Solution {
  private:
    int maxProfit(vector<int> &prices, int front, int to) {
      if (to - front < 2)
        return 0;
      int res = 0;
      int low = prices[front];

      for (int i = front+1; i < to; i++) {
        if (prices[i] < low) {
          low = prices[i];
        } else {
          res = max(res, prices[i] - low);
        }
      }
      return res;
    }

  public:
    int maxProfit(vector<int> &prices) {
      if (prices.size() < 2)
        return 0;
      vector<int> prefix(prices.size(), 0);
      vector<int> pos(prices.size(), 0);
      int res = 0;
      int low = prices[0];

      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < low) {
          low = prices[i];
        } else {
          res = max(res, prices[i] - low);
        }
        prefix[i] = res;
      }

      res = 0;
      int high = pos[prices.size() - 1];
      for (int i = prices.size() -1 ;i >= 0; i--) {
        if (prices[i] > high) {
          high = prices[i];
        } else {
          res = max(res, high - prices[i]);
        }
        pos[i] = res;
      }

      res = 0;
      for (int i = 0; i < prefix.size(); i++) {
        if (prefix[i] + pos[i] > res)
          res = prefix[i] + pos[i];
      }

      return res;
    }
};

int
main(int argc, char *argv[]) {
  vector<int> arr = {8,3,6,2,8,8,8,4,2,0,7,2,9,4,9};
  Solution solution;
  cout << solution.maxProfit(arr) << endl;
}
