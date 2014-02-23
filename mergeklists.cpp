/*
 * =====================================================================================
 *
 *       Filename:  mergeklists.cpp
 *
 *    Description:  Merge k sorted linked lists and return it as one sorted list. Anayze and describe its complexity.
 *
 *        Version:  1.0
 *        Created:  02/23/2014 03:53:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmial.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }
        ListNode *res = lists[0];
        int len = lists.size();
        for (int i = 1; i < len; i++) {
            res = merge2Lists(res, lists[i]);
        }
        return res;
    }
    
    ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode tmp(0), *tail, *t;
        tmp.next = NULL;
        tail = &tmp;
        
        while (l1 || l2) {
            if (l2 == NULL || (l1 && l1->val < l2->val)) {
                t = l1;
                l1 = l1->next;
            } else {
                t = l2;
                l2 = l2->next;
            }
                t->next = tail->next;
                tail->next = t;
                tail = tail->next;
        }
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
  int arr1[] = {-3, 1, 4, 5, 5,8, 9, 11, 14, 15};
  int arr2[] = {1, 2, 3, 4, 5};
  ListNode *head1 = fromArray(arr1, 10);
  ListNode *head2 = fromArray(arr2, 5);
  vector<ListNode *> lists;
  lists.push_back(head1);
  lists.push_back(head2);

  Solution solution;
  head1 = solution.mergeKLists(lists);
  solution.printList(head1);
  return 0;
}
