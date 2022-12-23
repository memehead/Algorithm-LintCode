#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/31
void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partitionArray(vector<int>& nums, int k) {
    if (nums.empty()) {
        return 0;
    }
    int pre = -1;
    int L = 0;
    int R = nums.size();
    while (L < R) {
        if (nums[L] < k) {
            swap(nums, L++, ++pre);
        } else {
            swap(nums, --R, L);
        }
    }

    return L;
}