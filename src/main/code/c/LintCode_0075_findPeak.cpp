#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/75
int findPeak(vector<int>& a) {
    if (a.empty() || a.size() < 2) {
        return -1;
    }

    int N = a.size();

    if (a[0] > a[1]) {
        return a[0];
    }
    if (a[N - 1] > a[N - 2]) {
        return a[N - 1];
    }

    int ans = -1;
    int L = 0;
    int R = N - 1;
    while (L <= R) {
        int M = L + ((R - L) >> 1);
        if (a[M] > a[M - 1] && a[M] > a[M + 1]) {
            return M;
        } else if (a[M] > a[M + 1]) {
            R = M - 1;
        } else if (a[M] > a[M - 1]) {
            L = M + 1;
        } else {
            // R = M - 1;
            L = M + 1;
        }
    }

    return ans;
}