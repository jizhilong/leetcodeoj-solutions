/*
 * =====================================================================================
 *
 *       Filename:  array2bst.cpp
 *
 *    Description:  Given an array where elements are sorted in ascending 
 *                  order, convert it to a height balanced BST.
 *
 *        Version:  1.0
 *        Created:  03/14/2014 07:21:00 PM
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    TreeNode *sortedArrayToBST(vector<int> &num, int s, int e) {
      if (s >= e) 
        return NULL;
      int rooti = (s+e) / 2;
      TreeNode *root = new TreeNode(num[rooti]);
      root->left = sortedArrayToBST(num, s, rooti);
      root->right = sortedArrayToBST(num, rooti+1, e);

      return root;
    }

  public:
      TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size());
      }
};

int
main(int argc, char *argv[]) {
  vector<int> arr = {1,2,3,4,5,6};
  Solution solution;
  TreeNode *root = solution.sortedArrayToBST(arr);
  cout << root->val << endl;
  cout << root->left->val << " " << root->right->val << endl;
}
