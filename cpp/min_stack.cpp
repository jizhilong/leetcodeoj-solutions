/*
 * =====================================================================================
 *
 *       Filename:  min_stack.cpp
 *
 *    Description:  Design a stack that supports push, pop, top and retriving the
 *                  minimum element in constant time.
 *
 *        Version:  1.0
 *        Created:  01/30/2015 08:44:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
  private:
    stack<int> nums;
    stack<int> mins;

  public:
    void push(int x) {
      nums.push(x);
      
      if (mins.empty() || mins.top() >= x)
        min.push(x);
    }

    void pop() {
      int t = nums.top(); nums.pop();

      if (t == mins.top())
        mins.pop();
    }

    int top() {
      return nums.top();
    }

    int getMin() {
      return mins.top();
    }
};
