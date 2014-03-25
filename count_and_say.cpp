/*
 * =====================================================================================
 *
 *       Filename:  count_and_say.cpp
 *
 *    Description:  The count-and-say sequence is the sequence of integers begin
 *                  ubg as follows:
 *                    1,11,21,1211,111221,...
 *                    1 is read off as "one 1" or 11.
 *                    11 is read off as "two 1s" or 21.
 *                    Given an integer n, generate the nth sequence.
 *
 *        Version:  1.0
 *        Created:  03/25/2014 08:46:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
      string res = "1";
      for (int i = 1; i < n; i++) {
        int count = 1;
        stringstream ss;
        for (int j = 1; j < res.length(); j++) {
          if (res[j] == res[j-1]) {
            count++;
          } else {
            ss << count << res[j-1];
            count = 1;
          }
        }
        ss << count << res[res.length() - 1];
        res = ss.str();
      }
      return res;
    }
};


int 
main()
{
  Solution solution;
  cout << solution.countAndSay(1) << endl;
  cout << solution.countAndSay(2) << endl;
  cout << solution.countAndSay(3) << endl;
  cout << solution.countAndSay(4) << endl;
  cout << solution.countAndSay(5) << endl;
  cout << solution.countAndSay(6) << endl;
  cout << solution.countAndSay(7) << endl;
}
