#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/147
void process(int n, vector<int>& res) {
    int start = n == 1 ? 0 : pow(10, n - 1);
    int end = pow(10, n);
    for (int i = start; i < end; i++) {
        int ans = 0;
        int cur = i;
        while (cur >= 10) {
            int temp = cur % 10;
            ans += pow(temp, n);
            cur = (cur - temp) / 10;
        }
        ans += pow(cur, n);
        if (ans == i) {
            res.push_back(i);
        }
    }
}

// 暴力求解
vector<int> getNarcissisticNumbers(int n) {
    vector<int> ans;
    process(n, ans);

    return ans;
}

// 打表
vector<int> getNarcissisticNumbers2(int n) {
    vector<vector<int>> res = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                               {},
                               {153, 370, 371, 407},
                               {1634, 8208, 9474},
                               {54748, 92727, 93084},
                               {548834},
                               {1741725, 4210818, 9800817, 9926315}};

    return res[n - 1];
}