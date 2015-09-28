/*
 * =====================================================================================
 *
 *       Filename:  largest_number.cpp
 *
 *    Description:  Given a list of non negative integers, arrange them such
 *                  that they form the largest number.For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *                  Note: The result may be very large, so you need to return a string instead of an integer.
 *
 *        Version:  1.0
 *        Created:  01/18/2015 10:23:32 PM
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
#include <numeric>
#include <algorithm>

using namespace std;

bool compare_alpha(string s1, string s2) {
  string::iterator it1 = s1.begin() + 1;
  string::iterator it2 = s2.begin() + 1;

  while (it1 != s1.end() && it2 != s2.end() && *it1 == *it2) {
    it1++;
    it2++;
  }
  if (it1 == s1.end()) {
    if (it2 == s2.end()) {
      return false;
    } else {
      return compare_alpha(s1, string(it2, s2.end()));
    }
  } else {
    if (it2 == s2.end()) {
      return compare_alpha(string(it1, s1.end()), s2);
    } else {
      return compare_alpha(string(it1, s1.end()),
                           string(it2, s2.end()));
    }
  }
  
  return false;
}

class Solution {
  public:
    string largestNumber(vector<int> &num) {
      vector<string> nums;
      for (vector<int>::iterator it=num.begin(); it != num.end(); it++) {
        nums.push_back(to_string(*it));
      }

      sort(nums.begin(), nums.end(), compare_alpha);

      string result = accumulate(nums.begin(), nums.end(), string(""));
      if (all_of(result.begin(), result.end(), [](char c){ return c=='0'; })) {
        return "0";
      }
      return result;
    }
};


int
main(int argc, char * argv[]){
  int nums[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  vector<int> vnums(nums, nums + sizeof(nums)/sizeof(int));

  Solution s;

  cout << s.largestNumber(vnums) << endl;
}
