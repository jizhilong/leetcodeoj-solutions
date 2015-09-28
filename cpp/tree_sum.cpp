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
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x), left(NULL), right(NULL) {
  };
};

class Solution {
  public:
    int sumNumbers(TreeNode *root) {
      if (root == NULL)
        return 0;
      queue<TreeNode *> q; q.push(root);
      queue<int>        qacc; qacc.push(0);
      int sum = 0;

      while (!q.empty()) {
        TreeNode *node = q.front(); q.pop();
        int acc = qacc.front(); qacc.pop();
        acc = acc*10 + node->val;

        if (node->left == NULL && node->right == NULL) {
          sum += acc;
        } else {
          if (node->left) {
            q.push(node->left);
            qacc.push(acc);
          }

          if (node->right) {
            q.push(node->right);
            qacc.push(acc);
          }
        }
      }

      return sum;
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
