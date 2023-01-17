#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/100
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int N = nums.size();
    int L = 0;
    int R = 0;

    while (R < N) {
        if (nums[L] != nums[R]) {
            nums[++L] = nums[R];
        }
        R++;
    }

    return L + 1;
}