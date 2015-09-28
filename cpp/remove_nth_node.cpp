/*
 * =====================================================================================
 *
 *       Filename:  remove_nth_node.cpp
 *
 *    Description:  Given a linked list, remove the nth node from the end of 
 *                  list and return its head;
 *
 *        Version:  1.0
 *        Created:  03/24/2014 10:11:08 AM
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode **tail = &head;
      int i = 0;
      ListNode *tmp;
      for (tmp = head; i < n; tmp = tmp->next, i++);
      for (;tmp; tmp = tmp->next, tail = &(*tail)->next);
      *tail = (*tail)->next;
      return head;
    }
};

int
main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  Solution solution;
  head = solution.removeNthFromEnd(head, 2);
  for (ListNode *tmp = head; tmp; tmp = tmp->next)
    cout << tmp->val << " ";
  cout << endl;
}
