/*
 * =====================================================================================
 *
 *       Filename:  insertion_sortlist.cpp
 *
 *    Description:  Sort a linked list using insertion sort.
 *
 *        Version:  1.0
 *        Created:  02/22/2014 14:10:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
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

  ListNode tmp(0);
  ListNode *tail = &tmp;
  for (int i = 0; i < len; i++) {
    tail->next = new ListNode(x[i]);
    tail = tail->next;
  }
  return tmp.next;
}

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
      if (head == NULL || head->next == NULL)
        return head;

      ListNode tmp(0);
      ListNode *n, *h, *t;
      tmp.next = head;
      n = head->next;
      head->next = NULL;
      while (n) {
        for (h = &tmp;h->next && h->next->val < n->val; h = h->next);
        t = n;
        n = n->next;
        t->next = h->next;
        h->next = t;
      }
      return tmp.next;
    }

    void printList(ListNode *head) {
      while (head) {
        cout << head->val << endl;
        head = head->next;
      }
    }
};


int
main(int argc, char *argv[])
{
  int arr1[] = {4, 19, 14, 5, -3, 1, 8, 5, 11, 15};
  int arr2[] = {1, 2, 3, 4, 5};
  ListNode *head1 = fromArray(arr1, 10);
  ListNode *head2 = fromArray(arr2, 5);

  Solution solution;
  head1 = solution.sortList(head1);
  solution.printList(head1);
  return 0;
}


