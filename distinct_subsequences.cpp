/*
 * =====================================================================================
 *
 *       Filename:  distinct_subsqquecnces.cpp
 *
 *    Description:  Given a string S and a string T, count the number of distin
 *                  ct subsequences of T in S. 
 *                  -----------------------------------------------------------
 *                  example
 *                    S = "rabbbit", T = "rabbit" 
 *                    returns 3.
 *                  ------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  03/14/2014 12:46:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int numDistinct(string S, string T) {

    }
};

int
main(int argc, char *argv[]) {
  Solution solution;
  string S = "rabbbit";
  string T = "rabbit";

  cout << solution.numDistinct(S, T) << endl;
  return 0;
}
