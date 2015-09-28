/**

 * Definition for singly-linked list.

 * public class ListNode {

 *     int val;

 *     ListNode next;

 *     ListNode(int x) { val = x; }

 * }

 */

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ret = tail = null;
        int inc = 0;

        while (l1 != null || l2 != null) {
            if (l1 != null) {
                inc += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                inc += l2.val;
                l2 = l2.next;
            }
            ListNode tmp = new ListNode(inc % 10);
            inc /= 10;
            if (ret == null) {
                ret = tail = tmp;
            } else {
                tail.next = tmp;
                tail = tmp;
            }
        }

        if (inc != 0) {
            tail.next = new ListNode(inc);
        }

        return ret;
    }
}
