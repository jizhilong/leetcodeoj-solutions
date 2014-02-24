/*
 * =====================================================================================
 *
 *       Filename:  btree_lvl.cpp
 *
 *    Description:  Given a binary tree, return the level order traversal
 *                  of its nodes' values.(ie, from left to right, level by level).
 *                  -------------------------------------------------------------------
 *                  {3,9,20,#,#,15,7} ==> [[3], [9, 20], [15, 7]]
 *                  -------------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  02/24/2014 03:29:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmial.com
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int> > levelOrder(TreeNode *root) {
      vector<vector<int> > res;
      if (root == NULL) {
          return res;   
      }

      queue<TreeNode *> q;
      queue<int> iq;
      q.push(root); 
      iq.push(0); 

      while (!q.empty()) {
        TreeNode *tmp = q.front(); q.pop();
        int i = iq.front(); iq.pop();

        if (tmp == NULL)
          continue;

        if (i == res.size())
          res.push_back(vector<int>());
        res[i].push_back(tmp->val);

        q.push(tmp->left);
        iq.push(i+1);
        q.push(tmp->right);
        iq.push(i+1);
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

  vector<vector<int> >  res = solution.levelOrder(root);

  for (int i = 0 ; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}
