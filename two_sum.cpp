/*
 * =====================================================================================
 *
 *       Filename:  two_sum.cpp
 *
 *    Description:  Given an array of integers, find two numbers such that they
 *                  add up to a specific target number.
 *
 *        Version:  1.0
 *        Created:  04/05/2014 08:52:08 PM
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

struct Node {
  int val;
  int i;

  Node(int x, int index): val(x), i(index+1) {}
};

bool compare_by_val(Node n1, Node n2) {
  return n1.val < n2.val;
}

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      vector<Node> nodes;
      for (int i = 0; i < numbers.size(); i++) {
        nodes.push_back(Node(numbers[i], i));
      }
      sort(nodes.begin(), nodes.end(), compare_by_val);

      vector<int> ret(2);
      for (int i = 0; i < nodes.size(); i++) {
        int t = target - nodes[i].val;
        int lo, hi;
        if (i == 0 || t > nodes[i].val) {
          lo = i+1;
          hi = numbers.size() - 1;
        } else {
          lo = 0;
          hi = i-1;
        }
        while (lo <= hi) {
          int mid = (lo+hi)/2;
          if (nodes[mid].val == t) {
            ret[0] = min(nodes[i].i, nodes[mid].i);
            ret[1] = max(nodes[i].i, nodes[mid].i);
            return ret;
          } else if (nodes[mid].val < t) {
            lo = mid+1;
          } else {
            hi = mid-1;
          }
        }
      }
    }
};

int
main()
{
  vector<int> numbers = {3,2,4};
  Solution solution;
  vector<int> ret = solution.twoSum(numbers, 6);
  cout << ret[0] << " " << ret[1] << endl;
}
