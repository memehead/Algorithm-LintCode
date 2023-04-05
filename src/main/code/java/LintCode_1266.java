package com.LintCode.algorithm;

/**
 * 找不同
 */
public class LintCode_1266 {
    public static char findTheDifference(String s, String t) {
        int[] array = new int[26];
        for (int i = 0; i < t.length(); i++) {
            array[t.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            array[s.charAt(i) - 'a']--;
        }

        char ans = ' ';
        for (int i = 0; i < 26; ++i) {
            if (array[i] != 0) {
                ans = (char) (i + 'a');
                break;
            }
        }
        return ans;
    }
}
