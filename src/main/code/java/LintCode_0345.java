package com.LintCode.algorithm;

/**
 * 数组求和（好像没有别的好的办法了）
 */
public class LintCode_0345 {
    public int[] getSum(int[] arr) {
        if (arr == null) {
            return null;
        }
        int N = arr.length;
        int[] res = new int[N];
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int k : arr) {
                if (k < arr[i]) {
                    sum += k;
                }
            }
            res[i] = sum;
        }
        return res;
    }
}
