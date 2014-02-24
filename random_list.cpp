/*
 * =====================================================================================
 *
 *       Filename:  random_list.cpp
 *
 *    Description:  A linked list is given such that each node contains an additional
 *                  random pointer which could point to any node in the list or null.
 *                  return a deep copy of the list
 *
 *        Version:  1.0
 *        Created:  02/24/2014 02:45:31 PM
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

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      for (RandomListNode *n = head; n;) {
        RandomListNode *tmp = new RandomListNode(n->label);
        tmp->next = n->next;
        n->next = tmp;
        n = tmp->next;
      }

      RandomListNode tmp(0);
      RandomListNode *tail = &tmp;

      for (RandomListNode *n = head; n; n = n->next->next) {
        if (n->random)
          n->next->random = n->random->next;
      }

      for (RandomListNode *n = head; n; n = n->next) {
        tail->next = n->next;
        tail = tail->next;
        n->next = tail->next;
      }

      return tmp.next;
    }
};

int
main(int argc, char *argv[])
{
  RandomListNode *h1 = new RandomListNode(1);
  RandomListNode *h2 = new RandomListNode(2);
  h1->next = h2;
  RandomListNode *h3 = new RandomListNode(3);
  h2->next = h3;
  RandomListNode *h4 = new RandomListNode(4);
  h3->next = h4;
  RandomListNode *h5 = new RandomListNode(5);
  h4->next = h5;
  RandomListNode *h6 = new RandomListNode(6);
  h5->next = h6;

  h1->random = h6;
  h3->random = h1;
  h4->random = h6;

  for (RandomListNode *h = h1; h; h = h->next) {
    cout << h->label << " ";
    if (h->random)
      cout << h->random->label;
    else
      cout << "NULL";
    cout << endl;
  }


  Solution solution;
  RandomListNode *copy = solution.copyRandomList(h1);
  cout << endl;
  for (RandomListNode *h = copy; h; h = h->next) {
    cout << h->label << " ";
    if (h->random)
      cout << h->random->label;
    else
      cout << "NULL";
    cout << endl;
  }
}
