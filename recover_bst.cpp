/*
 * =====================================================================================
 *
 *       Filename:  recover_bst.cpp
 *
 *    Description:  Two elements of a binary search tree are swapped by mistake.
 *                  Recover the tree without changing its structure.
 *
 *        Version:  1.0
 *        Created:  03/15/2014 11:23:23 AM
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
    TreeNode *s1, *s2, *pre;
    void inorder(TreeNode *root) {
      if (root == NULL)
        return;
      inorder(root->left);
      if (pre && root->val < pre->val) {
        if (s1 == NULL) {
          s1 = pre;
        }
        s2 = root;
      }

      pre = root;
      inorder(root->right);
    }

  public:
    void recoverTree(TreeNode *root) {
      if (root == NULL)
        return;
      s1 = s2 = pre = NULL;
      inorder(root);
      int tmp = s1->val;
      s1->val = s2->val;
      s2->val = tmp;
    }
};

int
main()
{
  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(1);
  Solution solution;
  solution.recoverTree(root);
  cout << root->val << " " << root->left->val << endl;
}
