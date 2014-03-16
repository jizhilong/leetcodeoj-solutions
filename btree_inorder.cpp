/*
 * =====================================================================================
 *
 *       Filename:  btree_inorder.cpp
 *
 *    Description:  Given a binary tree, return the inorder traversal of its nodes values.
 *
 *        Version:  1.0
 *        Created:  03/16/2014 02:43:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
      vector<int> res;
      if (root == NULL)
        return res;
      TreeNode *cur = root;

      while (cur) {
        if (cur->left == NULL) {
          res.push_back(cur->val);
          cur = cur->right;
        } else {
          TreeNode *tmp = cur->left;
          for(;tmp->right && tmp->right != cur; tmp = tmp->right);
          if (tmp->right == NULL) {
            tmp->right = cur;
            cur = cur->left;
          } else {
            res.push_back(cur->val);
            tmp->right = NULL;
            cur = cur->right;
          }
        }
      }

      return res;
    }
};

int
main() {
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(2);
  vector<int> res = solution.inorderTraversal(root);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}
