/*
 * =====================================================================================
 *
 *       Filename:  simplify_path.cpp
 *
 *    Description: Given an absolute path for a file (Unix-style), simplify it. 
 *
 *        Version:  1.0
 *        Created:  04/07/2014 02:58:00 PM
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
#include <stack>

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {
      stack<string> stk;
      int s = 0;
      int e = path.find('/',s);
      e = e == string::npos ? path.size() : e;

      for (; s <= path.size();){
        string substr = path.substr(s, e-s);
        if (substr == "" || substr == ".") {
        } else if (substr == "..") {
          if (!stk.empty())
            stk.pop();
        } else {
          stk.push(substr);
        }
        s = e+1;
        e = path.find('/',s);
        e = e == string::npos ? path.size() : e;
      }


      string ret = "";
      while (!stk.empty()) {
        ret = "/" + stk.top() + ret;
        stk.pop();
      }
      if (ret == "")
        ret = "/";
      return ret;
    }
};

int
main()
{
  Solution solution;
  cout << solution.simplifyPath("/../");
}
