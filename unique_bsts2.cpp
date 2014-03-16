/*
 * =====================================================================================
 *
 *       Filename:  unique_bsts2.cpp
 *
 *    Description:  Given n, generate all structurally unique BST's that store
 *                  values 1..n.
 *
 *        Version:  1.0
 *        Created:  03/16/2014 02:57:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
  private:
    TreeNode *copy(TreeNode *root) {
      if (root == NULL)
        return root;
      TreeNode *croot = new TreeNode(root->val);
      croot->left = copy(root->left);
      croot->right = copy(root->right);
      return root;
    }

    vector<TreeNode *> generateTrees(vector<int> &nums, int s, int e) {
      vector<TreeNode *> res;
      if (s > e)
        return res;
      if (s == e) {
        res.push_back(NULL);
        return res;
      }

      for (int i = s; i < e; i++) {
        vector<TreeNode *> resl = generateTrees(nums, s, i);
        vector<TreeNode *> resr = generateTrees(nums, i+1, e);

        for (auto itl = resl.begin(); itl != resl.end(); itl++) {
          for (auto itr = resr.begin(); itr != resr.end(); itr++) {
            TreeNode *root = new TreeNode(nums[i]);
            root->left = *itl;
            root->right = *itr;
            res.push_back(root);
          }
        }
      }

      return res;
    }

  public:
    vector<TreeNode *> generateTrees(int n) {
      vector<int> nums(n);
      for (int i = 0; i < n; i++)
        nums[i] = i+1;
      return generateTrees(nums, 0, n);
    }
};

int
main()
{
  Solution solution;
  vector<TreeNode *> trees = solution.generateTrees(1);
  assert(trees.size() == 1);
  trees = solution.generateTrees(2);
  assert(trees.size() == 2);
  trees = solution.generateTrees(3);
  assert(trees.size() == 5);
  trees = solution.generateTrees(4);
  assert(trees.size() == 14);
}
