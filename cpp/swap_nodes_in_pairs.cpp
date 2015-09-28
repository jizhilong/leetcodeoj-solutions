/*
 * =====================================================================================
 *
 *       Filename:  swap_nodes_in_pairs.cpp
 *
 *    Description:  Given a linked list, swap every two adjacent nodes and 
 *                  return its head.
 *                  For example, given 1->2->3->4, you should return 2->1->4->3.
 *
 *        Version:  1.0
 *        Created:  03/21/2014 10:49:56 AM
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
  ListNode *swapPairs(ListNode *head) {
    ListNode **res = &head;
    for (ListNode *node = head;node && node->next;) {
      if (node->next) {
        ListNode *tmp = node->next->next;
        *res = node->next;
        node->next->next = node;
        node->next = tmp;
        node = tmp;
        res = &((*res)->next->next);
      } 
    }
    return head;
  }
};

int
main()
{
  ListNode *head = new ListNode(1);
  ListNode *node = head;
  for (int i = 2; i < 5; i++) {
    node->next = new ListNode(i);
    node = node->next;
  }

  Solution solution;
  head = solution.swapPairs(head);
  for (node = head; node; node = node->next)
    cout << node->val << " ";
  cout << endl;
}
