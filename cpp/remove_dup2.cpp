/*
 * =====================================================================================
 *
 *       Filename:  remove_dup2.cpp
 *
 *    Description:  Given a sorted linked list, delete all nodes that have 
 *                  duplicate numbers, leaving only distinct numbers from the
 *                  original list.
 *
 *        Version:  1.0
 *        Created:  03/20/2014 03:54:34 PM
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
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode **tail = &head;
      while (*tail) {
        ListNode *node;
        for (node = (*tail)->next; node && node->val == (*tail)->val; node = node->next);
        if (node != (*tail)->next) {
          *tail = node;
        } else {
          tail = &((*tail)->next);
        }
      }
      return head;
    }
};

int
main()
{
  ListNode *head= new ListNode(1), *tail;
  head->next = new ListNode(1); tail = head->next;
  tail->next = new ListNode(3); tail = tail->next;
  tail->next = new ListNode(3); tail = tail->next;
  tail->next = new ListNode(3); tail = tail->next;

  Solution solution;
  head = solution.deleteDuplicates(head);
  for (ListNode *node = head; node; node = node->next)
    cout << node->val << " ";
  cout << endl;
}
