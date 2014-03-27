/*
 * =====================================================================================
 *
 *       Filename:  rotate_list.cpp
 *
 *    Description:  Given a list, rotate the list to the right by k place, where
 *                  k is non-negative.For example:
 *                  Given 1->2->3->4->5->NULL and k = 2
 *                  return 4->5->1->2->3->NULL
 *
 *        Version:  1.0
 *        Created:  03/27/2014 11:37:40 PM
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
    ListNode *rotateRight(ListNode *head, int k) {
      if (k == 0 || head == NULL)
        return head;

      ListNode *fast, *slow;
      int i;
      for (i = 0, fast = head; i < k && fast; fast = fast->next, i++);

      if (fast == NULL) {
        return rotateRight(head, k % i);
      }
      for (slow = head; fast->next; fast = fast->next, slow = slow->next);
      ListNode *res = slow->next;
      slow->next = NULL;
      fast->next = head;
      return res;
    }
};


int
main()
{
  ListNode *res = new ListNode(1);
  res->next = new ListNode(2);
  res->next->next = new ListNode(3);
  res->next->next->next = new ListNode(4);
  res->next->next->next->next = new ListNode(5);

  Solution solution;
  res = solution.rotateRight(res, 1);
  for (ListNode *tmp = res; tmp; tmp = tmp->next)
    cout << tmp->val << " ";
  cout << endl;
}
