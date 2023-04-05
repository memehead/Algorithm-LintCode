package com.LintCode.algorithm;

import java.util.ArrayList;
import java.util.List;

/**
 * 寻找素数 （100以内）
 */
public class LintCode_0298 {
    public static void main(String[] args) {
        List<Integer> res = prime(100);
        System.out.println(res);
    }

    public static List<Integer> prime(int n) {
        List<Integer> res = new ArrayList<>();
        if (n <= 1) {
            return res;
        }
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                res.add(i);
            }
        }

        return res;
    }

    private static boolean isPrime(int n) {
        for (int i = 2; i < n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
