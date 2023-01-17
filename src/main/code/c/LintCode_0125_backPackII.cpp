#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/125/
int process(vector<int>& a, vector<int>& v, int index, int rest) {
    if (index == a.size()) {
        return 0;
    }
    int p1 = process(a, v, index + 1, rest);

    int p2 = 0;
    if (rest - a[index] >= 0) {
        p2 = process(a, v, index + 1, rest - a[index]) + v[index];
    }

    return max(p1, p2);
}

// 暴力递归
int backPackII(int m, vector<int>& a, vector<int>& v) {
    if (a.empty() || v.empty() || a.size() != v.size()) {
        return 0;
    }

    return process(a, v, 0, m);
}

// 动态规划
int dp(int m, vector<int>& a, vector<int>& v) {
    if (a.empty() || v.empty() || a.size() != v.size()) {
        return 0;
    }
    int N = a.size();
    vector<vector<int>> dp(N + 1, vector<int>(m + 1));

    for (int index = N - 1; index >= 0; --index) {
        for (int rest = 0; rest <= m; ++rest) {
            dp[index][rest] = dp[index + 1][rest];

            if (rest - a[index] >= 0) {
                dp[index][rest] = max(
                    dp[index][rest], dp[index + 1][rest - a[index]] + v[index]);
            }
        }
    }

    return dp[0][m];
}

// 动态规划（空间压缩）
int optimizeDp(int m, vector<int>& a, vector<int>& v) {
    if (a.empty() || v.empty() || a.size() != v.size()) {
        return 0;
    }
    int N = a.size();
    vector<int> dp(m + 1);

    for (int index = N - 1; index >= 0; --index) {
        for (int rest = m; rest >= 0; --rest) {
            if (rest - a[index] >= 0) {
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
    for (int i = 0; i < 1000; ++i) {
        vector<int> a = generateRandomVector(10, 10);
        vector<int> v = generateRandomVector(10, 10);
        int m = rand() % 20;
        int res = backPackII(m, a, v);
        int ans = dp(m, a, v);
        int answer = optimizeDp(m, a, v);

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