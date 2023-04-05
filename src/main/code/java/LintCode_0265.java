package com.LintCode.algorithm;

import java.util.Arrays;

/**
 * 最大非负子序和（考虑以每个位置结尾的最大值）
 */
public class LintCode_0265 {
    public static void main(String[] args) {
        int[] array = {1, 2, -3, 4, 5, -6};
        int ans = maxNonNegativeSubArray(array);
        System.out.println(ans);
    }

    public static int maxNonNegativeSubArray(int[] a) {
        if (a == null || a.length == 0) {
            return -1;
        }

        int N = a.length;

        int[] dp = new int[N];
        dp[0] = a[0] >= 0 ? a[0] : -1;

        int maxRes = dp[0];
        for (int i = 1; i < N; i++) {
            if (a[i] >= 0) {
                dp[i] = Math.max(a[i], a[i] + (dp[i - 1] != -1 ? dp[i - 1] : 0));
            } else {
                dp[i] = -1;
            }
            maxRes = Math.max(dp[i], maxRes);
        }
        System.out.println(Arrays.toString(dp));

        return maxRes;
    }
}
