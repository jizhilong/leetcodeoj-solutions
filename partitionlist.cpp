/*
 * =====================================================================================
 *
 *       Filename:  partionlist.cpp
 *
 *    Description:  Given a linked list and a value x, partition it such that all nodes less
 *                  than x come before nodes greater than or equal to x.You should preserve 
 *                  the original relative order of the nodes in each of the two partitions.
 *                  --------------------------------------------------------------
 *                  Given 1->4->3->2->5->2 and x = 3/
 *                  return 1->2->2->4->3->5.
 *                  --------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  02/23/2014 04:12:57 PM
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
  ListNode(int x):val(x), next(NULL) {}
  ListNode(int x, ListNode *n):val(x), next(n) {}
};

ListNode *fromArray(int *arr, int len) {
  ListNode tmp(0);
  ListNode *tail = &tmp;
  for (int i = 0; i < len; i++, tail = tail->next) {
    tail->next = new ListNode(arr[i]);
  }
  return tmp.next;
}

class Solution {
  public:

  ListNode *partition(ListNode *head, int x) {
    ListNode lt(0), gt(0);
    ListNode *ltp = &lt, *gtp = &gt, *t, **tail;

    while (head) {
      if (head->val < x) {
        tail = &ltp;
      } else {
        tail = &gtp;
      }
      t = head;
      head = head->next;
      t->next = (*tail)->next;
      (*tail)->next = t;
      *tail = t;
    }
    ltp->next = gt.next;
    return lt.next;
  }

  void printList(ListNode *head){
    for (; head; head = head->next)
      cout << head->val << endl;
  }
};

int
main(int argc, char *argv[]) {
  int nums[] = {1,4,3,2,5,2};
  ListNode *head = fromArray(nums, 6);

  Solution solution;
  head = solution.partition(head, 3);
  solution.printList(head);
}
