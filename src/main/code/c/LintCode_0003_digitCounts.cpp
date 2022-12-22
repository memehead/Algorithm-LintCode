#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/3
int digitCounts(int k, int n) {
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i >= 0 && i < 10) {
            if (i == k) {
                ans++;
            }
        } else if (i >= 10 && i < 100) {
            int shi = i / 10;
            int ge = i % 10;
            if (shi == k) {
                ans++;
            }
            if (ge == k) {
                ans++;
            }
        } else if (i >= 100 && i < 1000) {
            int bai = i / 100;
            int shi = i % 100 / 10;
            int ge = i % 100 % 10;
            if (bai == k) {
                ans++;
            }
            if (shi == k) {
                ans++;
            }
            if (ge == k) {
                ans++;
            }
        } else if (i >= 1000 && i < 10000) {
            int qian = i / 1000;
            int bai = i % 1000 / 100;
            int shi = i % 1000 % 100 / 10;
            int ge = i % 1000 % 100 % 10;
            if (qian == k) {
                ans++;
            }
            if (bai == k) {
                ans++;
            }
            if (shi == k) {
                ans++;
            }
            if (ge == k) {
                ans++;
            }

        } else if (i >= 10000 && i < 100000) {
            int wan = i / 10000;
            int qian = i % 10000 / 1000;
            int bai = i % 10000 % 1000 / 100;
            int shi = i % 10000 % 1000 % 100 / 10;
            int ge = i % 10000 % 1000 % 100 % 10;
            if (wan == k) {
                ans++;
            }
            if (qian == k) {
                ans++;
            }
            if (bai == k) {
                ans++;
            }
            if (shi == k) {
                ans++;
            }
            if (ge == k) {
                ans++;
            }
        } else {
            if (k == 1) {
                ans++;
            }
            if (k == 0) {
                ans += 5;
            }
        }
    }

    return ans;
}