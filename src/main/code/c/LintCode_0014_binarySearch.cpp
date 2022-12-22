#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/14
int binarySearch(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int L = 0;
    int R = nums.size() - 1;

    int ans = -1;
    while (L <= R) {
        int M = L + ((R - L) >> 1);
        if (nums[M] > target) {
            R = M - 1;
        } else if (nums[M] < target) {
            L = M + 1;
        } else {
            ans = M;
            R = M - 1;
        }
    }

    return ans;
}