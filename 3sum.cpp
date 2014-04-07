/*
 * =====================================================================================
 *
 *       Filename:  3sum.cpp
 *
 *    Description:  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 *        Version:  1.0
 *        Created:  04/07/2014 06:17:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    int bin_search(vector<int> &num, int target, int lo) {
      int hi = num.size() - 1;
      int mid;
      int m;

      while (lo <= hi) {
        mid = lo + ((hi - lo) >> 1);
        m = num[mid];

        if (target == m) {
          return mid;
        } else if (target < m) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      return -1;
    }

    vector<vector<int> > twoSum(vector<int> &num, int target, int lo) {
      vector<vector<int> > ret;

      for (int i = lo; i < num.size();) {
        int j;
        int m;
        for (j = i+1; j < num.size() && num[j] == num[i]; j++);
        if (j - i >= 2 && 2*num[i] == target) {
          ret.push_back(vector<int>(2, num[i]));
        }
        if ((m = bin_search(num, target - num[i], j)) != -1) {
          ret.push_back(vector<int>());
          ret.back().push_back(num[i]);
          ret.back().push_back(num[m]);
        } 
        i = j;
      }
      return ret;
    }

public:

    vector<vector<int> > threeSum(vector<int> &num) {
      sort(num.begin(), num.end());
      vector<vector<int> > ret;

      for (int i = 0; i < num.size();) {
        int j;
        for (j = i+1; j < num.size() && num[j] == num[i]; j++);

        if (j-i >= 3 && num[i] == 0) {
          ret.push_back(vector<int>(3, 0));
        }

        if (j-i >= 2) {
          int m;
          if ((m = bin_search(num, -2*num[i], j)) != -1) {
            ret.push_back(vector<int>(2, num[i]));
            ret.back().push_back(num[m]);
          }
        }

        vector<vector<int> > tmp = twoSum(num, -num[i], j);
        for (int k = 0; k < tmp.size(); k++) {
          ret.push_back(tmp[k]);
          ret.back().insert(ret.back().begin(), num[i]);
        }
        i = j;
      }

      return ret;
    }
};


int
main(int argc, char *argv[])
{
  vector<int> nums = {-1, 0, 2, 1, -1, -4};
  Solution solution;
  vector<vector<int> > ret = solution.threeSum(nums);
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i][0] << " " << ret[i][1] << " " << ret[i][2] << endl;
  }
}
