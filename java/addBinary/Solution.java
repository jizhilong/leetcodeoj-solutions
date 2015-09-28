public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int inc = 0;
        int i = a.length() - 1, j = b.length() - 1;

        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                inc += a.charAt(i--) - '0';
            }
            if (j >= 0) {
                inc += b.charAt(j--) - '0';
            }
            sb.append(inc % 2);
            inc /= 2;
        }

        if (inc != 0)
            sb.append(1);

        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.addBinary(args[0], args[1]));
    }
}
