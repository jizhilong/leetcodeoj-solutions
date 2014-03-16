/*
 * =====================================================================================
 *
 *       Filename:  validae_bst.cpp
 *
 *    Description:  Given a binary tree, determin if it is a valid binary search
 *                  tree.Assume a BST is defined as follows:
 *                    The left subtree of a node contains only nodes with keys 
 *                    less than the node's key.
 *                    The right subtree of a node contains only nodes with keys
 *                    greater than node's key.
 *                    Both the left and right subtrees must also be binary 
 *                    search trees.
 *
 *        Version:  1.0
 *        Created:  03/16/2014 01:17:51 PM
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
#include <stdlib.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  private:
    TreeNode *pre;
    bool inorder(TreeNode *root) {
      if (root == NULL)
        return true;
      if (inorder(root->left)) {
        if (pre && root->val <= pre->val) {
          return false;
        } else {
          pre = root;
          return inorder(root->right);
        }
      } else {
        return false;
      }
    }

  public:
    bool isValidBST(TreeNode *root) {
      if (root == NULL)
        return true;
      pre = NULL;
      return inorder(root);
    }
};

int
main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(20);
  Solution solution;
  assert(solution.isValidBST(root) == false);
}
