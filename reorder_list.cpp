/*
 * =====================================================================================
 *
 *       Filename:  reorder_list.cpp
 *
 *    Description:  Given a singly linked list L: L0->L1->L2...=>Ln
 *                  reorder it to: L0->Ln->L1->Ln-1->->...
 *                  ------------------------------------------------------
 *                  {1,2,3,4} -> {1,4,2,3}
 *                  ------------------------------------------------------
 *        Version:  1.0
 *        Created:  02/23/2014 08:23:48 PM
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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode *slow = head, *fast = head->next->next;
        for (; fast && fast->next; slow = slow->next, fast = fast->next->next);
        
        fast = inverseList(slow->next);
        slow->next = NULL;
        intersectLists(head, fast);
    }
    
    ListNode *inverseList(ListNode *head) {
        ListNode *prev = NULL, *tmp;
        while (head) {
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    
    void intersectLists(ListNode *l1, ListNode *l2) {
        ListNode *node;
        while (l1->next && l2) {
            node = l2;
            l2 = l2->next;
            node->next = l1->next;
            l1->next = node;
            l1 = node->next;
        }
        if (l1->next == NULL)
          l1->next = l2;
    }

    void printList(ListNode *head) {
      for (; head; head = head->next)
        cout << head->val << endl;
    }
};

int
main(int argc, char *argv[])
{
  int arr1[] = {1, 2, 3, 4, 5};
  ListNode *head1 = fromArray(arr1, 5);
  
  Solution solution;
  solution.reorderList(head1);
  solution.printList(head1);
  return 0;
}
