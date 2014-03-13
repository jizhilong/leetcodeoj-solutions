/*
 * =====================================================================================
 *
 *       Filename:  populating_next_right_pointers.cpp
 *
 *    Description:  Given a binary tree, populate each next pointer to its next 
 *                  right node. If there is no next right node, the next pointer
 *                  should be set to NULL. Initially, all next pointers are set
 *                  to NULL.
 *                  NOTE:
 *                    You may only use constant extra space.
 *                    You may assume that it is a perfect binary tree.
 *
 *        Version:  1.0
 *        Created:  03/13/2014 09:26:17 PM
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
      if (root == NULL)
        return;
      int count = 1, level = 1;
      TreeLinkNode *node = root;;
      node->next = node->left;

      while (node) {
        count++;
        if (node->left) {
          node->left->next = node->right;
          node->right->next = node->next ? node->next->left : NULL;
        }
        if (count == 1 << level) {
          level++;
          TreeLinkNode *tmp = node->next;
          node->next = NULL;
          node = tmp;
        } else {
          node = node->next;
        }
      }
    }
};

int
main(int argc, char *argv[]) {
  TreeLinkNode *root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right= new TreeLinkNode(3);
  root->left->left = new TreeLinkNode(4);
  root->left->right = new TreeLinkNode(5);
  root->right->left = new TreeLinkNode(6);
  root->right->right = new TreeLinkNode(7);

  Solution solution;
  solution.connect(root);
  cout << root->left->next->val << endl;
}
