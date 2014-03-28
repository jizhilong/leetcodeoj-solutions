/*
 * =====================================================================================
 *
 *       Filename:  4sum.cpp
 *
 *    Description:  Given an array S of n integers, are there elements a,b,c,and
 *                  d in S such that a+b+c+d=target?Find all unique quadruplets
 *                  in the array which gives the sum of target.
 *                  Note:
 *                    Elements in a quadruplet (a,b,c,d) must be in non-descending order.
 *                    The solution set must not contain duplicate quadruplets.
 *
 *        Version:  1.0
 *        Created:  03/28/2014 08:41:40 AM
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

      if (target < dp[s][k-1] || target > dp[num.size() - k][k-1]) {
        return;
      }

      if (k == 1) {
        int lo = s, hi = num.size() - 1;
        while (lo <= hi) {
          int mid = (lo+hi)/2;
          if (num[mid] == target) {
            vector<int> restmp(4,target);
            int h = 2;
            LN *tmp = prev;
            for (; h >= 0; h--, tmp = tmp->next)
              restmp[h] = tmp->val;
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
        vector<int> restmp(4, num[s]);
        int h = 4-k-1;
        LN *tmp = prev;
        for (; h >= 0; h--, tmp = tmp->next)
          restmp[h] = tmp->val;
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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
      sort(num.begin(), num.end());
      int len = num.size();

      if (len < 4)
        return vector<vector<int> >();

      dp = vector<vector<int> >(len, vector<int>(4,0));

      for (int i = len - 1; i >= 0; i--) {
        dp[i][0] = num[i];
        for (int j = 2; j <= 4 && j <= len - i; j++) {
          dp[i][j-1] = dp[i+1][j-2] + num[i];
        }
      }

      kSum(num, 0, 4, target, NULL);
      return res;
    }
};

int
main() {
  vector<int> num = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824246};
  Solution solution;
  vector<vector<int> > res = solution.fourSum(num, -236727523);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
