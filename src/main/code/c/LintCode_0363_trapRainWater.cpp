#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/363/
int trapRainWater(vector<int>& heights) {
    if (heights.empty() || heights.size() < 3) {
        return 0;
    }

    int N = heights.size();
    int ans = 0;
    int leftMax = heights[0];
    int rightMax = heights[N - 1];
    int L = 1;
    int R = N - 2;

    while (L <= R) {
        if (leftMax <= rightMax) {
            ans += max(0, leftMax - heights[L]);
            leftMax = max(leftMax, heights[L++]);
        } else {
            ans += max(0, rightMax - heights[R]);
            rightMax = max(rightMax, heights[R--]);
        }
    }

    return ans;
}