#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/60
int searchInsert(vector<int>& a, int target) {
    if (a.empty()) {
        return 0;
    }

    int N = a.size();
    if (target < a[0]) {
        return 0;
    }
    if (target > a[N - 1]) {
        return N;
    }

    int L = 0;
    int R = N - 1;

    int ans = -1;
    bool flag = false;
    while (L <= R) {
        int M = L + ((R - L) >> 1);

        if (a[M] == target) {
            flag = true;
            ans = M;
            break;
        } else if (a[M] > target) {
            R = M - 1;
        } else if (a[M] < target) {
            L = M + 1;
        }
    }

    return flag ? ans : L;
}