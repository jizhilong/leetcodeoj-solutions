/*
 * =====================================================================================
 *
 *       Filename:  intersection_of_two_linked_lists.cpp
 *
 *    Description:  Write a program to find the node at which the intersection of two singly
 *                  linked lists begins.
 *
 *        Version:  1.0
 *        Created:  01/27/2015 08:27:12 PM
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (headA == NULL || headB == NULL)
        return NULL;
      ListNode *tailB;
      for (tailB = headB; tailB->next; tailB = tailB->next);
      
      tailB->next = headA;
      ListNode *fast=headB->next->next, *slow=headB->next;
      while (fast && fast->next && fast->next->next &&
             slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
      }

      if (fast != slow || slow == NULL) {
        tailB->next = NULL;
        return NULL;
      }

      fast = headB;
      while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
      }
      tailB->next = NULL;
      return slow;
    }
};


int
main(int argc, char *argv[]) {
  int i = 1;
  Solution s;
  ListNode *a = new ListNode(i);
  ListNode *hb = new ListNode(2);
  ListNode *ha = a;
  while (i < 4) {
    i += 2;
    a->next = new ListNode(i);
    a = a->next;
  }
  cout << s.getIntersectionNode(ha, ha) << endl;

}
