/*
 * =====================================================================================
 *
 *       Filename:  reverse_list.cpp
 *
 *    Description:  Reverse a linked list from position m to n. Do it in-place and in 
 *                  one-pass. For example:
 *                  --------------------------------------------------------------------
 *                  Given 1->2->3->4->5->NULL, m = 2 and n = 4;
 *                  return 1->4->3->2->5->NULL;
 *                  --------------------------------------------------------------------
 *                  NOTE:
 *                  1<=m<=n<=length of list
 *
 *        Version:  1.0
 *        Created:  02/24/2014 11:27:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmial.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode **tmp = &head;
        ListNode *start, *tail, *end;
        int i;
        for (i = 1, start = &tmp; i < m; start = start->next, i++);
        tail = start;
        for (end = start->next; i <= n;i++) {
            ListNode *t = end->next;
            end->next = tail;
            tail = end;
            end = t;
        }

        start->next->next = end;
        start->next = tail;
        return tmp.next;
    }

    void printList(ListNode *head) {
      for (; head; head = head->next)
        cout << head->val << endl;
      cout << endl;
    }
};

int
main(int argc, char *argv[])
{
  int arr1[] = {5};
  ListNode *head1 = fromArray(arr1, 1);

  Solution solution;
  head1 = solution.reverseBetween(head1, 1, 1);
  solution.printList(head1);
  return 0;
}
