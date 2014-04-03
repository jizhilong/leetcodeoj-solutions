/*
 * =====================================================================================
 *
 *       Filename:  merge_intervals.cpp
 *
 *    Description:  Given a collection of intervals, merge all overlapping intervals.
 *                  For example,
 *                    Given [1,3],[2,6],[8,10],[15,18]
 *                    return [1,6],[8,10],[15,18]
 *
 *        Version:  1.0
 *        Created:  04/04/2014 02:17:56 AM
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

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool compare_by_start(Interval itl1, Interval itl2) {
  return itl1.start < itl2.start;
}

class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
      vector<Interval> res;
      if (intervals.empty())
        return res;
      sort(intervals.begin(), intervals.end(), compare_by_start);
      res.push_back(intervals[0]);
      for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start > res.back().end) {
          res.push_back(intervals[i]);
        } else {
          res.back().end = max(res.back().end, intervals[i].end);
        }
      }

      return res;
    }
};

int
main() {
  vector<Interval> intervals = {Interval(1,3),Interval(2,6), Interval(8,10),Interval(15,18)};
  Solution solution;
  vector<Interval> res = solution.merge(intervals);
  for (int i = 0; i < res.size(); i++) {
    cout << "[" << res[i].start << "," << res[i].end << "]" <<endl;
  }
}
