/*
 * =====================================================================================
 *
 *       Filename:  max_points.cpp
 *
 *    Description:  Given n points on a 2D plane, find the maximum number of points
 *                  that lie on the same straight line.
 *
 *        Version:  1.0
 *        Created:  02/18/2014 09:14:12 PM
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

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b): x(a), y(b) {}
};


bool compare_by_x(Point p1, Point p2) {
  return p1.x < p2.x;
}


class Solution {
  public:
    int maxPoints(vector<Point> &points) {
      if (points.size() <= 2)
        return points.size();
      sort(points.begin(), points.end(), compare_by_x);
      int res = 2;
      for (int i = 0; i < points.size();i++) {
        int l;
        for (l = i + 1; l < points.size() && points[l].x == points[i].x && points[i].y == points[l].y; l++);
        l--;
        int n = l - i + 1; /* number of the same points */
        i = l;
        if (n > res) res = n;
        for (int j = i + 1; j < points.size(); j++) {
            int l;
            for (l = j + 1; l < points.size() && points[l].x == points[j].x && points[j].y == points[l].y; l++);
            l--;
            int tmp = n + l - j + 1;
            j = l;

            if (points[i].x == points[j].x) {
               int k;
               for (k = j+1; k < points.size() && points[k].x == points[j].x; k++);
               k--;
               tmp += k - j;
               if (tmp > res) res = tmp;
               continue;
            }

            if (points[i].y == points[j].y) {
              for (int k = j+1; k < points.size(); k++) {
                if (points[k].y == points[j].y)
                  tmp++;
              }
              if (tmp > res) res = tmp;
              continue;
            } 


            int dx = points[j].x - points[i].x;
            int dy = points[j].y - points[i].y;
            int x = points[j].x;
            int y = points[j].y;

            for (int k = j+1; k < points.size(); k++) {
              int xx = points[k].x, yy = points[k].y;
              if ((xx - x)*dy == (yy -y)*dx)
                tmp++;
            }
            if (tmp > res) res = tmp;
        }
      }

      return res;
    }
};

int
main()
{
  Solution solution;
  vector<Point> points;
  points.push_back(Point(1, 1));
  points.push_back(Point(1, 1));
  points.push_back(Point(1, 1));
  cout << solution.maxPoints(points) << endl;
  return 0;
}
