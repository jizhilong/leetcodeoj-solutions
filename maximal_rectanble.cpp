/*
 * =====================================================================================
 *
 *       Filename:  maximal_rectanble.cpp
 *
 *    Description:  Given a 2D binary matrix filled with 0's and 1's, find the
 *                  largest rectangle containing all ones and return its area.
 *                  ----------------------------------------------------------
 *                  0101110
 *                  1010111
 *                  1110011
 *                  0011001
 *                  1010110
 *                  0000111
 *                  1111111
 *
 *        Version:  1.0
 *        Created:  03/19/2014 09:21:04 PM
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
#include <string>

using namespace std;

struct Coord {
  int x;
  int y;
  Coord(int i, int j) : x(i), y(j) {}

  int area() {
    return x*y;
  }
};

#define L(i, j) dp[i][j-1]
#define U(i, j) dp[i-1][j]
#define LU(i, j) dp[i-1][j-1]

class Solution {
  public:
    int maximalRectangle(vector<string > &matrix) {
      int res = 0;
      if (matrix.empty())
        return res;
      vector<vector<Coord> > dp(matrix.size(), vector<Coord>(matrix[0].size(), Coord(0,0)));
      if (matrix[0][0] == '1') {
        dp[0][0].x = dp[0][0].y = 1;
        res = 1;
      }

      for (int i = 1; i < matrix[0].size(); i++) {
        if (matrix[0][i] == '1') {
          dp[0][i].y = 1;
          dp[0][i].x = L(0, i).x + 1;
          res = max(res, dp[0][i].area());
        }
      }

      for (int i = 1; i < matrix.size(); i++) {
        if (matrix[i][0] == '1') {
          dp[i][0].x = 1;
          dp[i][0].y = U(i, 0).y + 1;
          res = max(res, dp[i][0].area());
        }
      }

      for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
          if (matrix[i][j] == '0') {
            dp[i][j].x = 0; dp[i][j].y = 0;
          } else {
            dp[i][j].x = L(i, j).x + 1;
            dp[i][j].y = U(i, j).y + 1;

            int w = dp[i][j].x;   /* width */
            int h = 1;
            int area = 0;
            for (int ii = i; ii >= 0; ii--) {
              h = i - ii + 1;
              w = min(w, dp[ii][j].x);
              area = max(area, w*h);
            }
            res = max(area, res);
          }
        }
      }

      return res;
    }
};

int
main()
{
  vector<string> matrix = {"0110111111111111110","1011111111111111111","1101111111110111111","1111111111111011111","1111111111111101111","1110111011111111101","1011111111111101111","1111111111111110110","0011111111111110111","1101111111011111111","1111111110111111111","0110111011111111111","1111011111111101111","1111111111111111111","1111111111111111111","1111111111111111101","1111111101101101111","1111110111111110111"};
  Solution solution;
  cout << solution.maximalRectangle(matrix) << endl;
}
