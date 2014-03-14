/*
 * =====================================================================================
 *
 *       Filename:  flatten_btree.cpp
 *
 *    Description:  Given a binary tree, flatten it to a linked list in place.
 *
 *        Version:  1.0
 *        Created:  03/14/2014 02:32:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution {
  public:
    void flatten(TreeNode *root) {
      stack<TreeNode*> s;
      if (root)
        s.push(root);
      TreeNode *result;
      TreeNode **tail = &result;
      
      while (!s.empty()) {
        TreeNode *node = s.top(); s.pop();
        *tail = node;
        tail = &node->right;

        if (node->right) s.push(node->right);
        if (node->left) {
           s.push(node->left);
           node->left = NULL;
        }
      }
    }
};

int
main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);

  Solution solution;
  solution.flatten(root);

  for (TreeNode *tmp = root; tmp; tmp = tmp->right) {
    cout << tmp->val << " ";
    assert(tmp->left == NULL);
  }
  cout << endl;
}
