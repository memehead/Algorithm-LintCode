#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/428/
double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }

    bool flag = n < 0;
    int m = n == INT_MIN ? n + 1 : n;
    m = m < 0 ? -m : m;

    double ans = 1.0;
    double help = x;
    while (m != 0) {
        if ((m & 1) == 1) {
            ans *= help;
        }
        help *= help;
        m >>= 1;
    }

    ans = n == INT_MIN ? ans * x : ans;
    return flag ? 1 / ans : ans;
}