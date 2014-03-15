/*
 * =====================================================================================
 *
 *       Filename:  btree_zigzag.cpp
 *
 *    Description:  Given a binary tree, return the zigzag level order travesal
 *                  of its nodes' values. (ie. from left to right, then right to
 *                  left for the next level and alternate between).
 *                  -----------------------------------------------------------
 *                  given {3,9,20,#,#,15,7}
 *                  returns [[3],[20,9], [15,7]]
 *                  -----------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  03/15/2014 09:20:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
      vector<vector<int> > result;
      if (root == NULL)
        return result;

      queue<TreeNode *> q;
      queue<int> lvls;
      int lastlvl = -1;
      q.push(root);
      lvls.push(0);

      while (!q.empty()) {
        TreeNode *node = q.front(); q.pop();
        int lvl = lvls.front(); lvls.pop();

        if (lvl > lastlvl) {
          result.push_back(vector<int>());
          lastlvl++;
        }
        if (lvl % 2 == 0) {
          result.back().push_back(node->val);
        } else {
          result.back().insert(result.back().begin(), node->val);
        }

        if (node->left) {
          q.push(node->left);
          lvls.push(lvl+1);
        }

        if (node->right) {
          q.push(node->right);
          lvls.push(lvl+1);
        }
      }
      return result;
    }
};

int
main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution solution;
  vector<vector<int> > res = solution.zigzagLevelOrder(root);

  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto it1 = it->begin(); it1 != it->end(); it1++) {
      cout << *it1 << " ";
    }
    cout << endl;
  }
}
