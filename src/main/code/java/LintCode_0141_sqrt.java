package LintCode;

// https://www.lintcode.com/problem/125/
public class LintCode_0141_sqrt {
    public int sqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x < 3) {
            return 1;
        }

        long ans = -1;
        long L = 0;
        long R = x - 1;
        while (L <= R) {
            long M = L + ((R - L) >> 1);
            if (M * M < x) {
                ans = M;
                L = M + 1;
            } else if (M * M > x) {
                R = M - 1;
            } else {
                return (int) M;
            }
        }

        return (int) ans;
    }
}
