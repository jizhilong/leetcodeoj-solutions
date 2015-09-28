/*
 * =====================================================================================
 *
 *       Filename:  path_sum2.cpp
 *
 *    Description:  Given a binary tree and a sum, find all root-to-leaf paths 
 *                  where each path's sum equals the given sum.
 *
 *        Version:  1.0
 *        Created:  03/14/2014 04:05:11 PM
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

struct TransNode {
  int total;
  TreeNode *node;
  TransNode *prev;
  TransNode(TreeNode *n, TransNode *p) : node(n), prev(p) {
    total = n->val + (p ? p->total : 0);
  };
};

class Solution {
  public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
      queue<TransNode *> q;
      if (root) {
        q.push(new TransNode(root, NULL));
      }
      vector<vector<int> > res;

      while (!q.empty()) {
        TransNode *n = q.front(); q.pop();
        if (n->total == sum && n->node->left == NULL && n->node->right == NULL) {
          res.push_back(vector<int>());
          for (TransNode *tmp = n; tmp; tmp = tmp->prev) {
            res.back().insert(res.back().begin(), tmp->node->val);
          }
          continue;
        }

        if (n->node->left) {
          q.push(new TransNode(n->node->left, n));
        }
        if (n->node->right) {
          q.push(new TransNode(n->node->right, n));
        }
      }

      return res;
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
  root->right->right->left = new TreeNode(5);

  Solution solution;
  vector<vector<int> > res = solution.pathSum(root, 22);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
