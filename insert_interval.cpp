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
      if (intervals.empty()) {
        ret.push_back(newInterval);
        return ret;
      }
      int e;
      for (e = intervals.size() - 1; e >= 0 && intervals[e].start > newInterval.end; e--);
      if (e >= 0)
        newInterval.end = max(newInterval.end, intervals[e].end);
      int s;
      for (s = 0; s <= e && intervals[s].end < newInterval.start; s++);
      if (s <= e)
        newInterval.start = min(newInterval.start, intervals[s].start);

      ret.insert(ret.begin(), intervals.begin(), intervals.begin() + s);
      ret.push_back(newInterval);
      ret.insert(ret.end(), intervals.begin() + e + 1, intervals.end());
      return ret;
    }
};


int
main()
{

  vector<Interval> intervals = {Interval(1,5)};
  Solution solution;
  vector<Interval> res = solution.insert(intervals, Interval(6, 8));
  for (int i = 0; i < res.size(); i++) {
    cout << "[" << res[i].start << "," << res[i].end << "]" <<endl;
  }
}
