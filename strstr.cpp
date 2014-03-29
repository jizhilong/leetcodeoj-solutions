/*
 * =====================================================================================
 *
 *       Filename:  strstr.cpp
 *
 *    Description: Implement strStr().Returns a pointer to the first occurrence
 *                 of needle in haystack, or null if needle is not in haystack.
 *
 *        Version:  1.0
 *        Created:  03/29/2014 09:17:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
  public:
    char *strStr(char *haystack, char *needle) {
      int m = strlen(haystack);
      int n = strlen(needle);

      vector<int> skiptable(n, 0);
      for (int i = 1; i < n; i++) {
        int j;
        for (j = skiptable[i-1]; j > 0 && needle[j] != needle[i]; j = skiptable[j-1]);
        if (j || needle[j] == needle[i]) {
          skiptable[i] = j+1;
        }
      }

      int i, j;
      for (i = 0, j=0; i < m && j < n; i++) {
        for (;j > 0 && haystack[i] != needle[j]; j = skiptable[j-1]);
        if (j || haystack[i] == needle[j])
          j++;
      }

      return j == n ? haystack+i-n : NULL;
    }
};

int
main()
{
  char haystack[] = "mississippi";
  char needle[] = "issip";

  Solution solution;
  cout << solution.strStr(haystack, needle) << endl;
}
