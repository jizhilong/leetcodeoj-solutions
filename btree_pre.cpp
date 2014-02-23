/*
 * =====================================================================================
 *
 *       Filename:  btree_pre.cpp
 *
 *    Description:  Given a binary tree, return the preorder traversal of its nodes' values.
 *                  ---------------------------------------------------------------------
 *                  {1, #, 2, 3} -> [1,2,3]
 *
 *        Version:  1.0
 *        Created:  02/23/2014 06:45:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmial.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
      stack<TreeNode *> s;
      TreeNode *tmp;
      vector<int> res;
      if (root) s.push(root);

      while (!s.empty()) {
        tmp = s.top();
        s.pop();
        res.push_back(tmp->val);
        if (tmp->right) s.push(tmp->right);
        if (tmp->left) s.push(tmp->left);
      }

      return res;
    }
};

int
main(int argc, char *argv[])
{
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> res = solution.preorderTraversal(root);

  for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
    cout << *it << endl;
}
