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

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
      if (left == NULL && right == NULL)
        return true;
      if (left == NULL || right == NULL)
        return false;
      if (left->val == right->val) {
        return (isSymmetric(left->left, right->right) && 
               isSymmetric(left->right, right->left));
      } else {
        return false;
      }
    }

  public:
    bool isSymmetric(TreeNode *root) {
      if (NULL == root)
        return true;
      return isSymmetric(root->left, root->right);
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
