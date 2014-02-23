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
        slow = head;

        intersectLists(slow, fast);
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
        ListNode *tmp, *res;
        while (l1->next) {
            tmp = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
            l2 = tmp;
        }
        l1->next = l2;
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
  int arr1[] = {1, 2, 3, 4};
  int arr2[] = {-1,-2,-3,-4};
  ListNode *head1 = fromArray(arr1, 4);
  ListNode *head2 = fromArray(arr2, 4);
  
  Solution solution;
//  solution.intersectLists(head1, head2);
  solution.reorderList(head1);
  solution.printList(head1);
  return 0;
}
