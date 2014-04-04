/*
 * =====================================================================================
 *
 *       Filename:  inset_interval.cpp
 *
 *    Description: Given a set of non-overlapping intervals,insert a new interval
 *                 into the intervals(merge if necessary.) 
 *
 *        Version:  1.0
 *        Created:  04/04/2014 02:35:59 AM
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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      vector<Interval> ret;
      int i;
      for (i = 0; i < intervals.size() && intervals[i].start < newInterval.start; i++) {
        ret.push_back(intervals[i]);
      }

      if (ret.empty() || newInterval.start > ret.back().end) {
        ret.push_back(newInterval);
      } else {
        ret.back().end = max(ret.back().end, newInterval.end);
      }

      for (i; i < intervals.size(); i++) {
        if (intervals[i].start > ret.back().end) {
          ret.push_back(intervals[i]);
        } else {
          ret.back().end = max(ret.back().end, intervals[i].end);
        }
      }

      return ret;
    }
};


int
main()
{

  vector<Interval> intervals = {Interval(1,3),Interval(6,9)};
  Solution solution;
  vector<Interval> res = solution.insert(intervals, Interval(2, 5));
  for (int i = 0; i < res.size(); i++) {
    cout << "[" << res[i].start << "," << res[i].end << "]" <<endl;
  }
}
