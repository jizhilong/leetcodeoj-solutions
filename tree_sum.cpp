/*
 * =====================================================================================
 *
 *       Filename:  tree_sum.cpp
 *
 *    Description:  Given a binary tree containing digits from 0-9 only, each
 *                  root to leaf path could represent a number.An example is 
 *                  the root-to-leaf path 1->2->3 which represents the number
 *                  123.Find the total sum of all root-to-leaf numbers.
 *
 *        Version:  1.0
 *        Created:  03/09/2014 01:48:20 AM
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x), left(NULL), right(NULL) {
  };
};

class Solution {
  private:
    int sumNumbers(TreeNode *node, int acc) {
      if (node == NULL)
        return acc;

      acc = acc*10 + node->val;
      if (node->left == NULL && node->right == NULL)
        return acc;

      int res = 0;
      if (node->left)
        res += sumNumbers(node->left, acc);
      if (node->right)
        res += sumNumbers(node->right, acc);
      return res;
    }

  public:
    int sumNumbers(TreeNode *root) {
      return sumNumbers(root, 0);
    }
};

int
main(int argc, char *argv[])
{
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);

  cout << solution.sumNumbers(root) << endl;
}
