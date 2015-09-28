/*
 * =====================================================================================
 *
 *       Filename:  gas_station.cpp
 *
 *    Description:  There are N gas stations along a circular route, where the amount of
 *                  gas at station i is gas[i]. You have a car with an unlimited tank and
 *                  it costs cost[i] of gas to travel from station i to its next station 
 *                  i+1.You begin the journey with an empty tank at one of the gas stations.
 *                  Return the starting gas station's index if you can travel around the
 *                  circular once, otherwise return -1.
 *                  NOTE: The solution is guaranteed to be unique.
 *
 *        Version:  1.0
 *        Created:  02/25/2014 08:41:33 PM
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      vector<int> res;
      int len = gas.size();
      int sum = 0;
      for (int i = 0; i < len; i++) {
        int tmp = gas[i] - cost[i];
        sum += tmp;
        res.push_back(tmp);
      }
      
      if (sum < 0)
        return -1;

      int max, maxe;
      int s, se, e;

      int min, mine;
      int ms, mse, me;
      
      max = maxe = min = mine = res[0];
      s = se = e = ms = mse = me = 0;

      for (int i = 1; i < len; i++) {
        if (maxe > 0) {
          maxe += res[i];
        } else {
          maxe = res[i];
          se = i;
        }

        if (mine < 0) {
          mine += res[i];
        } else {
          mine = res[i];
          mse = i;
        }

        if (maxe > max) {
          max = maxe;
          s = se;
          e = i;
        }

        if (mine < min) {
          min = mine;
          ms = mse;
          me = i;
        }
      }

    if (max >= (sum - min)) {
      return s;
    } else {
      return (me+1) % len;
    }
    }
};

int
main(int argc, char *argv[])
{
  Solution solution;
  int gasr[] = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66}; 
  int costr[] = {27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
  vector<int> gas(gasr, gasr+sizeof(gasr)/sizeof(int));
  vector<int> cost(costr, costr+sizeof(costr)/sizeof(int));
  
  cout << solution.canCompleteCircuit(gas, cost) << endl;
}
