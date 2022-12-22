#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/39
void reverse(vector<int>& array, int L, int R) {
    while (L < R) {
        int temp = array[L];
        array[L++] = array[R];
        array[R--] = temp;
    }
}

void recoverRotatedSortedArray(vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return;
    }
    int index = -1;
    int N = nums.size();
    for (int i = 1; i < N; i++) {
        if (nums[i] < nums[i - 1]) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        reverse(nums, 0, index - 1);
        reverse(nums, index, N - 1);
        reverse(nums, 0, N - 1);
    }
}