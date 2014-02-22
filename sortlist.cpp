/*
 * =====================================================================================
 *
 *       Filename:  sortlist.cpp
 *
 *    Description:  Sort a linked list in O(nlogn) time using constant space complexity.
 *
 *        Version:  1.0
 *        Created:  02/21/2014 09:32:21 PM
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

class Solution {
  public:
    ListNode *mergeList(ListNode *&n1, int len1, ListNode *&n2, int len2) {
      if (0 == len2) {
        return n1;
      }

      ListNode tmp(0);
      ListNode *tail = &tmp;

      while (len1 || len2) {
        if (len2 == 0 || (len1 != 0 && n1->val < n2->val)) {
          tail->next = n1;
          n1 = n1->next;
          len1--;
        } else {
          tail->next = n2;
          n2 = n2->next;
          len2--;
        }
        tail = tail->next;
      }

      n1 = n2;
      n2 = tail;
      return tmp.next;
    }

    ListNode *sortList(ListNode *head) {
      int len = listLength(head);
      int n;
      if (len <= 1)
        return head;

      ListNode tmp(0);
      tmp.next = head;
      ListNode *h1, *h2, *tail;

      for (int sep = 1; sep < len; sep *= 2) {
        tail = &tmp;
        h1 = tmp.next;
        n = len;
        while (n > 0) {
          int i;
          int l1 = min(sep, n);
          for (i = 0, h2 = h1; i < l1; h2 = h2->next, i++);
          int l2 = min(sep, n - l1);
          tail->next = mergeList(h1, sep, h2, l2);
          tail = h2;
          n -= l1 + l2;
        }
      }

      if (tail)
        tail->next = NULL;
      return tmp.next;
    }

    int listLength(ListNode *head) {
      int res = 0;
      for (; head; head = head->next)
        res++;
      return res;
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
  ListNode *head1 = new ListNode(4, 
          new ListNode(19, 
            new ListNode(14,
              new ListNode(5,
                new ListNode(-3,
                  new ListNode(1,
                    new ListNode(8,
                      new ListNode(5,
                        new ListNode(11,
                          new ListNode(15, NULL))))))))));

  ListNode *head2 = new ListNode(1, 
      new ListNode(2, 
        new ListNode(3,
          new ListNode(4, 
            new ListNode(5, NULL)))));


  Solution solution;
  head1 = solution.sortList(head1);
  solution.printList(head1);
  return 0;
}


