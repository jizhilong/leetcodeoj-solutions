/*
 * =====================================================================================
 *
 *       Filename:  maximum_gap.cpp
 *
 *    Description:  Given an unsorted array, find the maximum difference between the
 *                  successive elements in its sorted form.
 *
 *        Version:  1.0
 *        Created:  02/04/2015 07:48:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
  public:
    int maximumGap(vector<int> &num) {
      int n = num.size();
      if (n < 2) return 0;
      int mi = *min_element(num.begin(), num.end());
      int ma = *max_element(num.begin(), num.end());
      if (mi == ma) return 0;

      int blen = n - 1;
      double gap = (ma - mi) * 1.0 / blen;
      vector<int> bs(2*n, -1);

      for (int i = 0; i < n; i++) {
        int bi = 2*(int)((num[i] - mi) / gap);
        if (bs[bi] == -1 || num[i] < bs[bi]) bs[bi] = num[i];
        if (bs[bi+1] == -1 || num[i] > bs[bi+1]) bs[bi+1] = num[i];
      }

      int ans = -1;
      int last_bound = mi;
      int m = bs.size();
      
      for (int i = 0; i < m; i+=2) {
        if (bs[i] == -1)
          continue;

        ans = max(ans, bs[i]-last_bound);
        last_bound = bs[i+1];
      }
      return ans;
    }
};


int
main(int argc, char *argv[])
{
  int nums[] = {1,3,5,7,0,10};
  vector<int> vnums = vector<int>(nums, nums+sizeof(nums)/sizeof(int));
  Solution s;
  cout << s.maximumGap(vnums) << endl;
}
