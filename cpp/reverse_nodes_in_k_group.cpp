/*
 * =====================================================================================
 *
 *       Filename:  reverse_nodes_in_k_group.cpp
 *
 *    Description:  Given a linked list, reverse the nodes of a linked list k
 *                  at a time and return its modified list.
 *                  If the number of nodes is not a multiple of k then left-out
 *                  nodes in the end should remain as it is.You may not alter
 *                  the values in the nodes, only nodes itself may be changed.
 *                  Only constant memory is allowed.
 *                  For example,
 *                  Given this linked list: 1->2->3->4->5
 *                  for k = 2, you should return: 2->1->4->3->5
 *                  for k = 3, you should return: 3->2->1->4->5
 *
 *        Version:  1.0
 *        Created:  03/26/2014 10:38:55 PM
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
    ListNode *reverseKGroup(ListNode *head, int k) {
      int len;
      ListNode *tmp;
      for (tmp = head, len = 0; tmp; tmp = tmp->next, len++);

      ListNode *res;
      ListNode **bucket = &res;
      while (k <= len) {
        ListNode *prev = head;
        ListNode *next = head->next;
        int i = 1;
        for (i; i < k; i++) {
          ListNode *tmp = next->next;
          next->next = prev;
          prev = next;
          next = tmp;
        }

        *bucket = prev;
        bucket = &(head->next);
        head = next;
        len -= k;
      }
      *bucket = head;

      return res;
    }

    void printList(ListNode *head) {
      for (; head; head = head->next)
        cout << head->val << endl;
      cout << endl;
    }
};

ListNode *fromArray(int *x, int len) {
  if (x == NULL || len <= 0)
    return NULL;

  ListNode *res;
  ListNode **tail = &res;
  for (int i = 0; i < len; i++) {
    *tail = new ListNode(x[i]);
    tail = &(*tail)->next;
  }
  return res;
}

int
main() {
  int arr1[] = {1,2,3,4, 5};
  ListNode *head1 = fromArray(arr1, sizeof(arr1)/sizeof(int));

  Solution solution;
  head1 = solution.reverseKGroup(head1, 5);
  solution.printList(head1);
  return 0;
}
