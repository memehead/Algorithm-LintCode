#include <iostream>
using namespace std;

// https://www.lintcode.com/problem/2
long long trailingZeros(long long n) {
    long long ans = 0;
    while (n != 0) {
        ans += (n / 5);
        n /= 5;
    }

    return ans;
}