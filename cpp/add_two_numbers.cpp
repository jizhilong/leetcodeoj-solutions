/*
 * =====================================================================================
 *
 *       Filename:  add_two_numbers.cpp
 *
 *    Description:  You are given two linked lists representing two non-negative
 *                  numbers. The digits are stored in reverse order and each of
 *                  their nodes contain a single digits.Add the two numbers and
 *                  return it as a linked list.
 *                  Input: (2->4->3) + (5->6->4)
 *                  Output: 7->0->8
 *
 *        Version:  1.0
 *        Created:  03/27/2014 10:15:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode *ret = NULL;
      ListNode **tail = &ret;
      int inc = 0;
      while (l1 || l2) {
        if (l1) {
          inc += l1->val;
          l1 = l1->next;
        }
        if (l2) {
          inc += l2->val;
          l2 = l2->next;
        }
        *tail = new ListNode(inc % 10);
        inc /= 10;
        tail = &(*tail)->next;
      }
      if (inc)
        *tail = new ListNode(inc);
      return ret;
    }
};

int
main()
{
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution solution;
  ListNode *res = solution.addTwoNumbers(l1, l2);

  for (ListNode *tmp = res; tmp; tmp = tmp->next)
    cout << tmp->val;
  cout << endl;
}
