#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/83
int singleNumberII(vector<int>& a) {
    if (a.empty()) {
        return -1;
    }
    if (a.size() == 1) {
        return a[0];
    }
    if (a.size() < 4) {
        return -1;
    }

    vector<int> map(32);
    for (int i = 0; i < a.size(); i++) {
        for (int bit = 31; bit >= 0; bit--) {
            if ((a[i] >> bit) & 1 == 1) {
                map[bit]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (map[i] % 3 == 1) {
            ans += pow(2, i);
        }
    }

    return ans;
}