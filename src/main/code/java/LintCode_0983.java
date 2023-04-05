package com.LintCode.algorithm;


import java.util.ArrayList;
import java.util.List;

/**
 * 棒球游戏（不用考虑异常输入）
 */
public class LintCode_0983 {
    public static void main(String[] args) {
        String[] array = {"-52", "-92", "-70", "C", "+", "26", "17", "+", "17", "+", "-27", "-46", "73", "D", "+", "D", "-25", "C", "84", "C"};
        int ans = calPoints(array);
        System.out.println(ans);
    }

    public static int calPoints(String[] ops) {
        if (ops == null) {
            return 0;
        }

        List<Integer> list = new ArrayList<>();
        int total = 0;
        for (String op : ops) {
            switch (op) {
                case "+":
                    list.add(list.get(list.size() - 1) + list.get(list.size() - 2));
                    break;
                case "D":
                    list.add(list.get(list.size() - 1) * 2);
                    break;
                case "C":
                    list.remove(list.size() - 1);
                    break;
                default:
                    list.add(Integer.valueOf(op));
            }
        }
        for (Integer integer : list) {
            total += integer;
        }

        return total;
    }
}
