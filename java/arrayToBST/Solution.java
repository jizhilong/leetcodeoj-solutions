/**

 * Definition for a binary tree node.

 * public class TreeNode {

 *     int val;

 *     TreeNode left;

 *     TreeNode right;

 *     TreeNode(int x) { val = x; }

 * }

 */

public class Solution {
    private TreeNode sortedArrayToBST(int[] nums, int s, int e) {
        if (s >= e)
            return null;
        int rooti = (s+e) / 2;
        TreeNode root = new TreeNode(nums[rooti]);
        root.left = sortedArrayToBST(nums, s, rooti);
        root.right = sortedArrayToBST(nums, rooti+1, e);

        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length);
    }
}
