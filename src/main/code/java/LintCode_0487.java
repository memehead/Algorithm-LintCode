package com.LintCode.algorithm;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/**
 * 姓名去重
 */
public class LintCode_0487 {
    public List<String> nameDeduplication(String[] names) {
        List<String> res = new ArrayList<>();
        if (names == null) {
            return res;
        }
        HashSet<String> set = new HashSet<>();
        for (String x : names) {
            set.add(x.toLowerCase());
        }
        res.addAll(set);
        return res;
    }
}
