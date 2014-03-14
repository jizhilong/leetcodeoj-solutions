/*
 * =====================================================================================
 *
 *       Filename:  populating_next_right_pointers2.cpp
 *
 *    Description: follow up for problem "Populating Next Right Pointers in Each
 *                 Node."Whay if the given tree could be any binary tree?Would 
 *                 your previous solution still work?
 *                 Note:
 *                    You may only use constant extra space.
 *
 *        Version:  1.0
 *        Created:  03/13/2014 10:01:01 PM
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

struct TreeLinkNode {
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  public:
    void connect(TreeLinkNode *root) {
      TreeLinkNode *head = root;;
      TreeLinkNode *tail = root;

      while (head) { /* the next pointer makes the nodes linked like a BFS path */
        if (head->left) {
          tail->next = head->left;
          tail = tail->next;
        }
        if (head->right) {
          tail->next = head->right;
          tail = tail->next;
        }
        head = head->next;
      }

      head = root; /* the left most node of the current row */
      while (head) { /* unlink the right most node the left most node of the next row */
        TreeLinkNode *nexthead = head->left ? head->left : head->right;
        TreeLinkNode *tmp = head;
        while (tmp->next != nexthead)
          tmp = tmp->next;
        tmp->next = NULL;
        while (nexthead && nexthead->left == NULL && nexthead->right == NULL)
          nexthead = nexthead->next;
        head = nexthead;
      }
    }
};

int
main(int argc, char *argv[]) {
  TreeLinkNode *root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right= new TreeLinkNode(3);
  root->left->left= new TreeLinkNode(4);
  root->left->right = new TreeLinkNode(5);
  root->right->left = new TreeLinkNode(6);
  root->right->right = new TreeLinkNode(7);

  Solution solution;
  solution.connect(root);
  for (TreeLinkNode *node = root; node; node = node->next) {
    cout << node->val << " ";
  }
  cout << endl;
  for (TreeLinkNode *node = root->left; node; node = node->next) {
    cout << node->val << " ";
  }
  cout << endl;
  for (TreeLinkNode *node = root->left->left; node; node = node->next) {
    cout << node->val << " ";
  }
  cout << endl;
}
