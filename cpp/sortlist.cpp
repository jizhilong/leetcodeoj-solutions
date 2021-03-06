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

ListNode *fromArray(int *x, int len) {
  if (x == NULL || len <= 0)
    return NULL;

  ListNode *res;
  ListNode **node = &res;
  for (int i = 0; i < len; i++) {
    *node = new ListNode(x[i]);
    node = &(*node)->next;
  }
  return res;
}

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
      int len = listLength(head);
      int n, i, l1, l2;
      if (len <= 1)
        return head;

      ListNode *res = head; 
      ListNode **node;  /* *node points to the tail of the merged list */
      ListNode *h1, *h2;

      for (int sep = 1; sep < len; sep *= 2) {
        node = &res;
        h1 = res;
        n = len;
        while (n > 0) {
          l1 = min(sep, n);
          l2 = min(sep, n - l1);
          n -= l1 + l2;
          for (i = 0, h2 = h1; i < l1; h2 = h2->next, i++);

          while (l1 || l2) {
            if (l2 == 0 || (l1 != 0 && h1->val < h2->val)) {
              *node = h1;
              h1 = h1->next;
              l1--;
            } else {
              *node = h2;
              h2 = h2->next;
              l2--;
            }
            node = &(*node)->next;
          }
         h1 = h2;
        }
      }

      *node = NULL;   /* set tail to NULL */
      return res;
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
  int arr1[] = {4, 19, 14, 5, -3, 1, 8, 5, 11, 15};
  int arr2[] = {1, 2, 3, 4, 5};
  ListNode *head1 = fromArray(arr1, 10);
  ListNode *head2 = fromArray(arr2, 5);

  Solution solution;
  head1 = solution.sortList(head1);
  solution.printList(head1);
  return 0;
}


