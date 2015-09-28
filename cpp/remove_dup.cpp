/*
 * =====================================================================================
 *
 *       Filename:  remove_dup.cpp
 *
 *    
 *    Description: remove duplicates from sorted list 
 *
 *        Version:  1.0
 *        Created:  03/20/2014 03:44:03 PM
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
      for (ListNode *tail = head; tail;) {
        ListNode *tmp;
        for (tmp = tail->next; tmp && tmp->val == tail->val; tmp = tmp->next);
        tail->next = tmp;
        tail = tmp;
      }
      return head;
    }
};

int
main()
{
  ListNode *head= new ListNode(1), *tail;
  head->next = new ListNode(1); tail = head->next;
  tail->next = new ListNode(2); tail = tail->next;
  tail->next = new ListNode(3); tail = tail->next;
  tail->next = new ListNode(3); tail = tail->next;

  Solution solution;
  head = solution.deleteDuplicates(head);
  for (ListNode *node = head; node; node = node->next)
    cout << node->val << " ";
  cout << endl;
}
