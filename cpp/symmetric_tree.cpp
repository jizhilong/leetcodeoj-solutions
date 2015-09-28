/*
 * =====================================================================================
 *
 *       Filename:  symmetric_tree.cpp
 *
 *    Description:  Given a binary tree, check whether it is a mirror of itself.
 *
 *        Version:  1.0
 *        Created:  03/15/2014 09:37:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <assert.h>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
      if (NULL == root)
        return true;
      queue<TreeNode *> lefts;
      queue<TreeNode *> rights;
      lefts.push(root->left);
      rights.push(root->right);

      while (!lefts.empty()) {
        TreeNode *left = lefts.front(); lefts.pop();
        TreeNode *right= rights.front(); rights.pop();
        if (left == NULL && right == NULL)
          continue;
        if (left == NULL || right == NULL)
          return false;
        if (left->val != right->val)
          return false;
        lefts.push(left->left); rights.push(right->right);
        lefts.push(left->right); rights.push(right->left);
      }

      return true;
    }
};


int
main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(2);
  root1->left->right = new TreeNode(3);
  root1->right->right = new TreeNode(3);

  Solution solution;
  assert(solution.isSymmetric(root));
  assert(!solution.isSymmetric(root1));
}
