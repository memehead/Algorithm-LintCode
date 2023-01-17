#include <iostream>
#include <vector>

using namespace std;

// https://www.lintcode.com/problem/220
// 打表失败
int getAnswer(int num) {
    if (num == 1) {
        return 0;
    }

    int ans = 0;
    if (num % 2 == 0) {
        num /= 2;
    } else {
        num = 3 * num + 1;
    }
    ans = getAnswer(num) + 1;

    return ans;
}