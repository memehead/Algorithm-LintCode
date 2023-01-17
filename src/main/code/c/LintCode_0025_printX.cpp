#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/25
void process(int L, int R, int n, vector<string>& res) {
    string temp = "";
    if (L == R) {
        for (int i = 0; i < n; i++) {
            temp.append(i == L ? "X" : " ");
        }
        res[L] = temp;
        return;
    }

    if (L == R - 1) {
        for (int i = 0; i < n; i++) {
            temp.append(i == L || i == R ? "X" : " ");
        }
        res[L] = temp;
        res[R] = temp;
        return;
    }

    for (int j = 0; j < n; j++) {
        temp.append(j == L || j == R ? "X" : " ");
    }

    res[L] = temp;
    res[R] = temp;

    process(L + 1, R - 1, n, res);
}

// 应该是遍历将对角线上的元素设置为'X'
vector<string> printX(int n) {
    if (n < 1 || n > 15) {
        vector<string> res;
        return res;
    }

    vector<string> res(n);
    process(0, n - 1, n, res);

    return res;
}
