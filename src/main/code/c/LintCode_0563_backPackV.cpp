#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/563/
int process(vector<int>& array, int index, int rest) {
    if (index == array.size()) {
        return rest == 0 ? 1 : 0;
    }

    int p1 = process(array, index + 1, rest);
    int p2 = 0;
    if (rest - array[index] >= 0) {
        // +有没有无关紧要
        p2 += process(array, index + 1, rest - array[index]);
    }

    return p1 + p2;
}

// 暴力递归
int backPackV(vector<int>& nums, int target) {
    if (nums.empty() || target == 0) {
        return 0;
    }

    return process(nums, 0, target);
}

// 动态规划
int dp(vector<int>& nums, int target) {
    if (nums.empty() || target == 0) {
        return 0;
    }

    int N = nums.size();
    vector<vector<int>> dp(N + 1, vector<int> (target + 1));
    dp[N][0] = 1;
    for (int index = N - 1; index >= 0; --index) {
        for (int rest = 0; rest <= target; ++rest) {
            dp[index][rest] = dp[index + 1][rest];

            if (rest - nums[index] >= 0) {
                dp[index][rest] += dp[index + 1][rest - nums[index]];
            }
        }
    }

    return dp[0][target];
}

// 动态规划（空间压缩）
int optimizeDp(vector<int>& nums, int target) {
    if (nums.empty() || target == 0) {
        return 0;
    }

    int N = nums.size();
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int index = N - 1; index >= 0; --index) {
        for (int rest = target; rest >= 0; --rest) {
            if (rest - nums[index] >= 0) {
                dp[rest] += dp[rest - nums[index]];
            }
        }
    }

    return dp[target];
}

// 生成随机长度的数组
vector<int> generateRandomVector(int maxSize, int maxValue) {
    int N = rand() % (maxSize + 1);
    unordered_set<int> set;
    while (N != 0) {
        set.insert(rand() % (maxValue + 1) + 1);
        --N;
    }

    vector<int> array(N);
    auto it = set.begin();
    while (it != set.end()) {
        array.push_back(*it);
        ++it;
    }

    return array;
}

int main(int argc, char const* argv[]) {
    bool flag = false;
    for (int i = 0; i < 1000; ++i) {
        vector<int> array = generateRandomVector(10, 10);
        int target = rand() % 20;

        int res = backPackV(array, target);
        int ans = dp(array, target);
        int answer = optimizeDp(array, target);

        if (res != ans || ans != answer || res != answer) {
            cout << res << endl;
            cout << ans << endl;
            cout << answer << endl;

            flag = true;
            break;
        }
    }

    cout << (!flag ? "Nice!" : "Fuck!") << endl;

    return 0;
}