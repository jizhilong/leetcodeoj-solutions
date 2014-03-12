/*
 * =====================================================================================
 *
 *       Filename:  btree_maximum_path.cpp
 *
 *    Description:  Given a binary tree, find the maximum path sum.
 *                  The path may start and end at any node in the tree.
 *                  For example:
 *                  Given the below bindry tree:
 *                            1
 *                           / \
 *                          2   3
 *                  Return 6.
 *
 *        Version:  1.0
 *        Created:  03/12/2014 01:21:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x), left(NULL), right(NULL) {};
};

struct Result {
  int res;  /* the actual result with the current node as root */
  int resl; /* the maximum path without any right child's node */
  int resr; /* the maximum path without any left child's node */

  Result(int n1, int n2, int n3):res(n1), resl(n2), resr(n3){};
};

class Solution {
  private:
    Result _maxPathSum(TreeNode *node) {
      if (node == NULL)
        return Result(0,0,0);

      Result l = _maxPathSum(node->left);
      Result r = _maxPathSum(node->right);
      int resl = node->val + max(0, max(l.resl, l.resr));
      int resr = node->val + max(0, max(r.resl, r.resr));
      int res = resl + resr - node->val;

      if (node->left && l.res > res)
        res = l.res;
      if (node->right && r.res > res)
        res = r.res;

      return Result(res, resl, resr);
    }

  public:
    int maxPathSum(TreeNode *root) {
      Result res = _maxPathSum(root);
      return root ? res.res : 0;
    }
};


int
main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(9);
  root->left = new TreeNode(6);
  root->right= new TreeNode(-3);
  root->right->left = new TreeNode(-6);
  root->right->right = new TreeNode(2);
  root->right->right->left = new TreeNode(2);
  root->right->right->left->left = new TreeNode(-6);
  root->right->right->left->right = new TreeNode(-6);
  root->right->right->left->left->left = new TreeNode(-6);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(-2);
  root2->right = new TreeNode(3);
  
  Solution solution;
  cout << solution.maxPathSum(root) << endl;
  cout << solution.maxPathSum(root2) << endl;
}
