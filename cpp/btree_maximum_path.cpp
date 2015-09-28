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
#include <stack>
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
  int resn;
  int resl; /* the maximum path without any right child's node */
  int resr; /* the maximum path without any left child's node */

  Result(Result *l, Result *r, TreeNode *n) {
      resr = resl = n->val;
      if (l)
        resl += l->resn;
      if (r)
        resr += r->resn;
      
      resn = max(0, max(resl, resr));
      res = resl + resr - n->val;
      if (l && l->res > res)
        res = l->res;
      if (r && r->res > res)
        res = r->res;
  }
};

class Solution {
  public:
    int maxPathSum(TreeNode *root) {
      stack<TreeNode *> s;
      stack<Result *> st;

      for (TreeNode *tmp = root; tmp; tmp = tmp->left) {
        s.push(tmp); s.push(tmp);
      }

      st.push(NULL);

      while (!s.empty()) {
        TreeNode *tmp = s.top(); s.pop();
        if (s.empty() || tmp != s.top()) {
          Result *r = st.top(); st.pop();
          Result *l = st.top(); st.pop();
          st.push(new Result(l, r, tmp));
      } else {
        for (TreeNode *node = tmp->right; node; node= node->left) {
          s.push(node);s.push(node);
        }
        st.push(NULL); 
      }
    }

      return st.top()->res;
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
  root2->right->left = new TreeNode(1);
  root2->right->right = new TreeNode(2);
  
  Solution solution;
  cout << solution.maxPathSum(root) << endl;
//  cout << solution.maxPathSum(root2) << endl;
}
