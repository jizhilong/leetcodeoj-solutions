/*
 * =====================================================================================
 *
 *       Filename:  longest_substr.cpp
 *
 *    Description:  Given a string, find the length of the longest substring 
 *                  without repeating characters. For example, the longest 
 *
 *        Version:  1.0
 *        Created:  03/27/2014 09:51:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      if (s.length() <= 1)
        return s.length();
      int max, maxe;
      max = maxe = 0;
      vector<int> lasts(256, -1);
      for (int i = 0; i < s.length(); i++) {
        if (lasts[s[i]] < i-maxe) {
          maxe++;
          max = maxe > max ? maxe : max;
        } else {
          maxe = i - lasts[s[i]];
        }
        lasts[s[i]] = i;
      }
      return max;
    }
};

int
main()
{
  string s = "abcabcbb";
  Solution solution;
  cout << solution.lengthOfLongestSubstring(s) << endl;
}
