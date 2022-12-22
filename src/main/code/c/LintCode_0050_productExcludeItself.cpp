#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/50
vector<long long> productExcludeItself(vector<int>& nums) {
    vector<long long> res;
    if (nums.empty()) {
        return res;
    }
    int N = nums.size();
    vector<long long> helpL(N);
    vector<long long> helpR(N);
    vector<long long> ans(N);

    helpL[0] = 1;
    for (int i = 1; i < N; i++) {
        helpL[i] = helpL[i - 1] * nums[i - 1];
    }

    helpR[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) {
        helpR[i] = helpR[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < N; i++) {
        ans[i] = helpL[i] * helpR[i];
    }

    return ans;
}