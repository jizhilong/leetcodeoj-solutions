/*
 * =====================================================================================
 *
 *       Filename:  compare_version_numbers.cpp
 *
 *    Description:  Compare two version numbers version1 and version2.
 *                  if version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *                  You may assume that the version strings are non-empty and contain only digits and '.'.
 *                  The '.' character does not represent a decimal point and is used to separate number sequences.
 *                  For instance, 2.5 is not two and a half or half way to version three, it is the fifth second level revision of the second first level revision.
 *                  Here is an example of version numbers ordering.
 *                  0.1 < 1.1 < 1.2 < 13.37
 *
 *        Version:  1.0
 *        Created:  01/19/2015 08:38:38 PM
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
    int compareVersion(string version1, string version2) {
      auto s1 = version1.begin();
      auto s2 = version2.begin();
      while (s1 != version1.end() || s2 != version2.end()) {
        auto e1 = s1;
        auto e2 = s2;
        while (e1 != version1.end() && *e1 != '.')
          e1++;
        while (e2 != version2.end() && *e2 != '.')
          e2++;

        int i1 = stoi(string("0") + string(s1, e1));
        int i2 = stoi(string("0") + string(s2, e2));
        if (i1 != i2)
          return i1 > i2 ? 1 : -1;
        s1 = e1 == version1.end() ? e1 : e1 + 1;
        s2 = e2 == version2.end() ? e2 : e2 + 1;
      }

      return 0;
    }
};

int
main(int argc, char *argv[]) {
  Solution s;
  cout << s.compareVersion("0.1", "1.1") << endl;
  cout << s.compareVersion("1.2", "1.1") << endl;
  cout << s.compareVersion("1.2", "13.37") << endl;
  cout << s.compareVersion("1.0", "1") << endl;
}
