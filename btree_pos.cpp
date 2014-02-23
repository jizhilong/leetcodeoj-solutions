/*
 * =====================================================================================
 *
 *       Filename:  btree_pos.cpp
 *
 *    Description:  Given a binary tree, return the postorder traversal of its nodes' values.
 *                  ---------------------------------------------------------------------
 *                  {1, #, 2, 3} -> [3, 2, 1]
 *
 *        Version:  1.0
 *        Created:  02/23/2014 06:36:42 PM
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
    vector<int> postorderTraversal(TreeNode *root) {
      stack<TreeNode *> s;
      vector<int> res;
      TreeNode *tmp;
      for (tmp = root; tmp != NULL; tmp = tmp->left) {
        s.push(tmp); s.push(tmp);
      }

      while (!s.empty()) {
        tmp = s.top();
        s.pop();
        if (s.empty() || tmp != s.top()) {
          res.push_back(tmp->val);
        } else {
          for (tmp = tmp->right; tmp != NULL; tmp = tmp->left) {
            s.push(tmp); s.push(tmp);
          }
        }
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

  vector<int> res = solution.postorderTraversal(root);

  for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
    cout << *it << endl;
}
