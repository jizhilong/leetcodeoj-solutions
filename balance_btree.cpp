/*
 * =====================================================================================
 *
 *       Filename:  balance_btree.cpp
 *
 *    Description:  Given a binary tree, determin if it is height balanced.
 *
 *        Version:  1.0
 *        Created:  03/14/2014 05:11:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    bool isBalanced(TreeNode *node, int &depth) {
      if (node == NULL) {
        depth = 0;
        return true;
      }

      int left, right;

      if (isBalanced(node->left, left) && isBalanced(node->right, right)) {
        if (abs(left-right) <= 1) {
          depth = max(left, right) + 1;
          return true;
        } else {
          return false;
        }
      }

      return false;
    }

  public:
    bool isBalanced(TreeNode *root) {
      int depth;
      return isBalanced(root, depth);
    }
};

int
main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->left = new TreeNode(3);

  Solution solution;
  cout << solution.isBalanced(root) << endl;
}
