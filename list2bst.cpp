/*
 * =====================================================================================
 *
 *       Filename:  list2bst.cpp
 *
 *    Description:  Given a singly linked list where elements are sorted in 
 *                  ascending order, convert it to a height blanced BST.
 *
 *        Version:  1.0
 *        Created:  03/14/2014 10:26:16 PM
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *sortedListToBST(ListNode *head) {
      if (head == NULL)
        return NULL;
      if (head->next == NULL)
        return new TreeNode(head->val);
      if (head->next->next == NULL) {
        TreeNode *root = new TreeNode(head->val);
        root->right = new TreeNode(head->next->val);
        return root;
      }
      ListNode *slow, *fast, *prev;

      for (prev = slow = fast = head; 
           fast && fast->next && fast->next->next;
           prev = slow, slow = slow->next, fast = fast->next->next);

      prev->next = NULL;
      TreeNode *root = new TreeNode(slow->val);
      root->left = sortedListToBST(head);
      root->right = sortedListToBST(slow->next);
      
      return root;
    }
};

int
main()
{
  ListNode *head= new ListNode(1);
  ListNode *tmp = head;
  for (int i = 2; i < 3; i++) {
    tmp->next = new ListNode(i);
    tmp = tmp->next;
  }

  Solution solution;
  TreeNode *root = solution.sortedListToBST(head);
  cout << root->val << endl;
  cout << root->left->val << endl;
}
