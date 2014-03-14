/*
 * =====================================================================================
 *
 *       Filename:  path_sum.cpp
 *
 *    Description:  Given a binary tree and a sum, determin if the tree has a 
 *                  root to leaf path such that adding up all the values along
 *                  the path equals the given sum.
 *
 *        Version:  1.0
 *        Created:  03/14/2014 03:44:32 PM
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

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  public:
    bool hasPathSum(TreeNode *root, int sum) {
      stack<TreeNode *> q;
      stack<int> acc;
      if (root) {
        q.push(root);
        acc.push(root->val);
      }

      while (!q.empty()) {
        TreeNode *node = q.top(); q.pop();
        int cur = acc.top(); acc.pop();
        if (cur == sum && node->left == NULL && node->right == NULL)
          return true;
        if (node->right) {
          q.push(node->right);
          acc.push(node->right->val + cur);
        }
        if (node->left) {
          q.push(node->left);
          acc.push(node->left->val + cur);
        }
      }

      return false;
    }
};

int
main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left  = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);

  Solution solution;
  cout << solution.hasPathSum(root, 22) << endl;
}
