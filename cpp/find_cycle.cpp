/*
 * =====================================================================================
 *
 *       Filename:  find_cycle.cpp
 *
 *    Description:  Given a linked list, return the node where the cycle begins. if there
 *                  is no cycle, return null;
 *
 *        Version:  1.0
 *        Created:  02/23/2014 06:57:28 PM
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

  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
      if (head == NULL || head->next == NULL)
        return NULL;
      ListNode *slow = head->next, *fast = slow->next;

      for (;slow && fast && fast->next; slow = slow->next, fast = fast->next->next) {
        if (slow == fast) {
          for (slow = head; slow != fast; slow = slow->next, fast = fast->next);
          return slow;
        }
      }

      return NULL;
    }
};


int
main(int argc, char *argv[]) {
  Solution solution;
  ListNode *h1 = new ListNode(0);
  ListNode *h2 = new ListNode(0);
  ListNode *h3 = new ListNode(0);

  ListNode *res;

  h1->next = h2;
  res = solution.detectCycle(h1);
  if (res) {
    cout << res->val << endl;
  } else {
    cout << "null" << endl;
  }
  h2->next = h1;
  res = solution.detectCycle(h1);
  if (res) {
    cout << res->val << endl;
  } else {
    cout << "null" << endl;
  }
  h2->next = h3;
  res = solution.detectCycle(h1);
  if (res) {
    cout << res->val << endl;
  } else {
    cout << "null" << endl;
  }
}
