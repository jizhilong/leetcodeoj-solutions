/*
 * =====================================================================================
 *
 *       Filename:  valid_number.cpp
 *
 *    Description:  Validate if a given string is numeric.Some examples:
 *                  "0" => true
 *                  " 0.1 " => true
 *                  "abc" => false
 *                  "1 a" => false
 *                  "2e10" => true
 *
 *        Version:  1.0
 *        Created:  04/12/2014 11:40:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <assert.h>
#include <ctype.h>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isNumber(const char *s) {
      while (isblank(*s)) s++;
      if (*s == '+' || *s == '-')
        s++;
      if (*s != '.' && !isdigit(*s))
        return false;
      if (*s == '.' && !isdigit(*(s+1)))
        return false;

      while (isdigit(*s)) s++;

      if (*s == '.') {
        s++;
        while (isdigit(*s)) s++;
      } 
      
      if (*s == 'e' || *s == 'E') {
        s++;
        if (*s == '+' || *s == '-')
          s++;
        if (!isdigit(*s))
          return false;
        while (isdigit(*s)) s++;
      }

      while (isblank(*s)) s++;
      return *s == '\0';
    }
};

int
main()
{
  Solution solution;
  assert(solution.isNumber("0"));
  assert(solution.isNumber(" 0.1 "));
  assert(!solution.isNumber("abc"));
  assert(!solution.isNumber("1 a"));
  assert(solution.isNumber("2e10"));
  assert(!solution.isNumber("e"));
  assert(solution.isNumber(".1"));
  assert(!solution.isNumber(" "));
  assert(!solution.isNumber("e9"));
  assert(solution.isNumber("01"));
  assert(solution.isNumber("3."));
  assert(!solution.isNumber("."));
  assert(solution.isNumber("-1."));
  assert(solution.isNumber("005047e+6"));
}
