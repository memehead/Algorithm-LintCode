#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/1310/
vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty() || nums.size() < 1) {
        return nums;
    }

    int N = nums.size();
    vector<int> ans(N, 1);
    for (int i = 1; i < N; i++) {
        ans[i] = nums[i -1] * ans[i - 1];
    }
    
    int pre = 1;
    int temp = 1;
    for (int i = N - 1; i >= 0; i--) {
        temp = pre * nums[i];
        ans[i] = ans[i] * pre;
        pre = temp;
    }

    return ans;
}