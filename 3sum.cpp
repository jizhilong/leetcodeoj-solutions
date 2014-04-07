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


#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

struct LN {
  int val;
  LN *next;
  LN(int x) : val(x), next(NULL) {};
};

class Solution {
  private:
    vector<vector<int> > dp;
    vector<vector<int> > res;

    void kSum(vector<int> &num, int s, int k, int target, LN *prev) {

      if (k > num.size() - s)
        return;

      if (k == 1) {
        int lo = s, hi = num.size() - 1;
        while (lo <= hi) {
          int mid = (lo+hi)/2;
          if (num[mid] == target) {
            vector<int> restmp(1,target);
            LN *tmp = prev;
            for (LN *tmp = prev; tmp; tmp = tmp->next)
              restmp.push_back(tmp->val);
            reverse(restmp.begin(), restmp.end());
            res.push_back(restmp);
            break;
          } else if (num[mid] < target) {
            lo = mid+1;
          } else {
            hi = mid-1;
          }
        }
        return;
      }

      int j;
      for (j = s+1; j < num.size() && num[j] == num[s]; j++);
      int bound = min(k-1, j-s);

      if (k <= j-s && num[s]*k == target) {
        vector<int> restmp(k, num[s]);
        LN *tmp = prev;
        for (LN *tmp = prev; tmp; tmp = tmp->next)
          restmp.push_back(tmp->val);
        reverse(restmp.begin(), restmp.end());
        res.push_back(restmp);
      }
        
      for (int n = 0; n <= bound; n++) {
        LN *tail = prev;
        for (int h = 0; h < n; h++) {
          LN *node = new LN(num[s]);
          node->next = tail;
          tail = node;
        }
        kSum(num, j, k - n, target-n*num[s], tail);
      }
    }

  public:
    vector<vector<int> > threeSum(vector<int> &num) {
      sort(num.begin(), num.end());

      kSum(num, 0, 3, 0, NULL);
      return res;
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
