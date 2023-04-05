package com.LintCode.algorithm;

/**
 * 幸运数字8
 */
public class LintCode_1385 {
    public static void main(String[] args) {
        System.out.println(luckyNumber(100));
    }
    public static int luckyNumber(int n) {
        if (n < 8) {
            return 0;
        }
        int total = 0;
        for (int i = 8; i <= n; ++i) {
            int j = i;
            while (j != 0) {
                int num = j % 10;
                if (num == 8) {
                    total++;
                    break;
                } else {
                    j /= 10;
                }
            }
        }

        return total;
    }
}
