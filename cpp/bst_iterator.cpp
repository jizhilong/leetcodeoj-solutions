/*
 * =====================================================================================
 *
 *       Filename:  bst_iterator.cpp
 *
 *    Description:  Implement an iterator over a binary search tree. Your iterator will
 *                  be initialized with the root node of a BST.
 *                  Calling next() will return the next smallest number in the BST.
 *                  Note: next() and hasNext() should run in average O(1) and uses O(h)
 *                  memory, where h is the height of the tree.
 *
 *        Version:  1.0
 *        Created:  01/27/2015 09:52:21 PM
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
  private:
    stack<TreeNode *> records;

  public:
    BSTIterator(TreeNode *root) {
      for(TreeNode *n = root; n; n = n->left)
        records.push(n);
    }

    bool hasNext() {
      return !records.empty();
    }

    int next() {
      TreeNode *n = records.top();
      records.pop();
      int res = n->val;
      for (n = n->right; n; n = n->left) {
        records.push(n);
      }
      return res;
    }
};


int
main(int argc, char *argb[])
{
  TreeNode *a = new TreeNode(2);
//  a->left = new TreeNode(1);
//  a->right = new TreeNode(3);

  BSTIterator i = BSTIterator(a);
  while (i.hasNext()) cout << i.next() << " ";

}
