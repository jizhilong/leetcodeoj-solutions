/*
 * =====================================================================================
 *
 *       Filename:  btree_fron_in_pos.cpp
 *
 *    Description:  Given inorder and postorder traversal of a tree, construct
 *                  the binary tree.
 *
 *        Version:  1.0
 *        Created:  03/15/2014 08:45:58 AM
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
    TreeNode *buildTree(vector<int> &inorder, int si, int ei, vector<int> &postorder, int sp, int ep) {
      if (si >= ei)
        return NULL;
      TreeNode *root = new TreeNode(postorder[ep-1]);
      int el;
      for (el = si; el < ei && inorder[el] != root->val; el++);
      root->left = buildTree(inorder, si, el, postorder, sp, sp + el - si);
      root->right = buildTree(inorder, el+1, ei, postorder, sp + el - si, ep - 1);
      return root;
    }

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

int
main()
{
  vector<int> inorder = {2,1,3};
  vector<int> posorder = {2,3,1};

  Solution solution;
  TreeNode *root = solution.buildTree(inorder, posorder);
  cout << root->val << endl;
  cout << root->left->val << endl;
  cout << root->right->val << endl;
}
