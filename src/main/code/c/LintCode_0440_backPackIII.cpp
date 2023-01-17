#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/440/
int process(vector<int>& a, vector<int>& v, int index, int rest) {
    if (index == a.size()) {
        return 0;
    }

    int ans = INT_MIN;
    for (int num = 0; num * a[index] <= rest; ++num) {
        ans = max(ans, process(a, v, index + 1, rest - num * a[index]) +
                           num * v[index]);
    }

    return ans;
}

// 暴力递归
int backPackIII(vector<int>& a, vector<int>& v, int m) {
    if (a.empty() || v.empty() || a.size() != v.size() || m <= 0) {
        return 0;
    }

    return process(a, v, 0, m);
}

// 动态规划
int dp(vector<int>& a, vector<int>& v, int m) {
    if (a.empty() || v.empty() || a.size() != v.size() || m <= 0) {
        return 0;
    }

    int N = a.size();
    vector<vector<int>> dp(N + 1, vector<int>(m + 1));

    for (int index = N - 1; index >= 0; --index) {
        for (int rest = 0; rest <= m; ++rest) {
            int ans = INT_MIN;
            for (int num = 0; num * a[index] <= rest; ++num) {
                ans = max(
                    ans, dp[index + 1][rest - num * a[index]] + v[index] * num);
            }

            dp[index][rest] = ans;
        }
    }

    return dp[0][m];
}

// 动态规划（斜率优化）
int optimizeDp(vector<int>& a, vector<int>& v, int m) {
    if (a.empty() || v.empty() || a.size() != v.size() || m <= 0) {
        return 0;
    }

    int N = a.size();
    vector<vector<int>> dp(N + 1, vector<int>(m + 1));

    for (int index = N - 1; index >= 0; --index) {
        for (int rest = 0; rest <= m; ++rest) {
            dp[index][rest] = dp[index + 1][rest];

            if (rest >= a[index]) {
                dp[index][rest] =
                    max(dp[index][rest], dp[index][rest - a[index]] + v[index]);
            }
        }
    }

    return dp[0][m];
}

// 动态规划（空间压缩）
int optimizeSpace(vector<int>& a, vector<int>& v, int m) {
    if (a.empty() || v.empty() || a.size() != v.size() || m <= 0) {
        return 0;
    }

    int N = a.size();
    vector<int> dp(m + 1);

    for (int index = N - 1; index >= 0; --index) {
        for (int rest = 0; rest <= m; ++rest) {
            if (rest >= a[index]) {
                dp[rest] = max(dp[rest], dp[rest - a[index]] + v[index]);
            }
        }
    }

    return dp[m];
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
    for (int i = 0; i < 50000; i++) {
        vector<int> a = generateRandomVector(20, 20);
        vector<int> v = generateRandomVector(20, 20);

        int m = rand() % 20;
        int res = backPackIII(a, v, m);
        int ans = dp(a, v, m);
        int answer = optimizeDp(a, v, m);
        int result = optimizeSpace(a, v, m);
        if (res != ans || res != answer || ans != answer || res != result) {
            cout << res << endl;
            cout << ans << endl;
            cout << answer << endl;
            cout << result << endl;

            flag = true;
            break;
        }
    }

    cout << (!flag ? "Nice!" : "Fuck!") << endl;

    return 0;
}