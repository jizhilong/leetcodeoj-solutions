/*
 * =====================================================================================
 *
 *       Filename:  btree_from_pre_in.cpp
 *
 *    Description:  Given preorder and inorder travesal of a tree, construct the
 *                  binary tree.
 *
 *        Version:  1.0
 *        Created:  03/15/2014 09:03:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  private:
    TreeNode *buildTree(vector<int> &preorder, int sp, int ep, vector<int> &inorder, int si, int ei) {
      if (sp >= ep)
        return NULL;
      TreeNode *root = new TreeNode(preorder[sp]);
      int el;
      for (el = si; el < ei && inorder[el] != root->val; el++);
      root->left = buildTree(preorder, sp+1, sp+1+el-si, inorder, si, el);
      root->right = buildTree(preorder, sp+1+el-si, ep, inorder, el+1, ei);

      return root;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

int
main()
{
  vector<int> preorder = {7, -10, -4, 3, -1, 2, -8, 11};
  vector<int> inorder = {-4, -10, 3, -1, 7, 11, -8, 2};
  Solution solution;
  TreeNode *root = solution.buildTree(preorder, inorder);
  cout << root->val << endl;
  cout << root->left->val << endl;
  cout << root->right->val << endl;
}
