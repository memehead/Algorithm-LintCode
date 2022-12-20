#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/767
void reverseArray(vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return;
    }

    int L = 0; 
    int R = nums.size() - 1;
    while (L < R)
    {
        int temp = nums[L];
        nums[L++] = nums[R];
        nums[R--] = temp;
    }
}