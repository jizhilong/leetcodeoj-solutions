/*
 * =====================================================================================
 *
 *       Filename:  detec_cycle.cpp
 *
 *    Description:  Given a linked list, determin if it has a cycle in it.
 *
 *        Version:  1.0
 *        Created:  02/23/2014 06:50:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmial.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) :val(x), next(NULL) {}
};


class Solution {
  public:
    bool hasCycle(ListNode *head) {
      if (!(head && head->next))
        return false;

      ListNode *slow = head->next, *fast = head->next->next;

      for (; slow && fast && fast->next;slow = slow->next, fast = fast->next->next) {
        if (slow == fast)
          return true;
      }

      return false;
    }
};

int
main(int argc, char *argv[]) {
  Solution solution;
  ListNode *h1 = new ListNode(0);
  ListNode *h2 = new ListNode(0);
  ListNode *h3 = new ListNode(0);

  h1->next = h2;
  cout << solution.hasCycle(h1) << endl;
  h2->next = h1;
  cout << solution.hasCycle(h1) << endl;
  h2->next = h3;
  cout << solution.hasCycle(h1) << endl;
}
