public class Solution {
    public int myAtoi(String str) {
        if (str == null) {
            return 0;
        }
        double ret = 0;
        int sign = 1;
        int i = 0;
        char c;
        str = str.trim();

        if (str.length() == 0) {
            return 0;
        }
        
        c = str.charAt(i);
        if (c == '+' || c == '-') {
            sign = c == '-' ? -1: 1;
            i++;
        }

        while (i < str.length() &&
               Character.isDigit((c = str.charAt(i++)))) {
            ret = ret*10 + (c - '0');
            if (sign > 0 && ret > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            } else if (sign < 0 && -ret < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
        }

        return (int)(sign*ret);
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.myAtoi(args[0]));
    }
}
