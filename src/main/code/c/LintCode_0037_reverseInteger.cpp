#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/37
int reverseInteger(int number) {
    if (number < 100 || number >= 1000) {
        return -1;
    }
    int ans = 0;
    int ge = number % 100 % 10;
    ans = ans * 10 + ge;

    int shi = number % 100 / 10;
    ans = ans * 10 + shi;

    int bai = number / 100;
    ans = ans * 10 + bai;

    return ans;
}