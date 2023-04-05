package com.LintCode.algorithm;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * 去除重复元素（有点扯的题）
 */
public class LintCode_0521 {
    public static void main(String[] args) {
        int[] array = {1, 3, 1, 4, 4, 2};
        int ans = deduplication(array);
        System.out.println(ans);
        System.out.println(Arrays.toString(array));
    }

    public static int deduplication(int[] nums) {
        if (nums == null) {
            return 0;
        }
        Set<Integer> set = new HashSet<>();
        for (int x : nums) {
            set.add(x);
        }
        int result = 0;
        for (Integer i : set) {
            nums[result++] = i;
        }
        return result;
    }
}
