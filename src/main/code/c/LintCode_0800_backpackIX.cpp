#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/800/
double process(vector<int>& prices,
               vector<double>& probability,
               int index,
               int rest) {
    if (index == prices.size()) {
        return 1.0;
    }
    double p1 = process(prices, probability, index + 1, rest);

    double p2 = 1.0;
    if (rest >= prices[index]) {
        p2 = process(prices, probability, index + 1, rest - prices[index]) *
             (1.0 - probability[index]);
    }

    return min(p1, p2);
}

// 暴力递归
double backpackIX(int n, vector<int>& prices, vector<double>& probability) {
    if (prices.empty() || probability.empty() || n <= 0) {
        return 0.0;
    }

    return 1.0 - process(prices, probability, 0, n);
}

// 动态规划
double dp(int n, vector<int>& prices, vector<double>& probability) {
    if (prices.empty() || probability.empty() || n <= 0) {
        return 0.0;
    }

    int N = prices.size();
    vector<vector<double>> dp(N + 1, vector<double>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[N][i] = 1.0;
    }

    for (int index = N - 1; index >= 0; --index) {
        for (int rest = 0; rest <= n; ++rest) {
            dp[index][rest] = dp[index + 1][rest];
            if (rest >= prices[index]) {
                dp[index][rest] =
                    min(dp[index][rest], dp[index + 1][rest - prices[index]] *
                                             (1.0 - probability[index]));
            }
        }
    }

    return 1.0 - dp[0][n];
}

// 动态规划（空间压缩）
double optimizeDp(int n, vector<int>& prices, vector<double>& probability) {
    if (prices.empty() || probability.empty() || n <= 0) {
        return 0.0;
    }

    int N = prices.size();
    vector<double> dp(n + 1, 1.0);

    for (int index = N - 1; index >= 0; --index) {
        for (int rest = n; rest >= 0; --rest) {
            if (rest >= prices[index]) {
                dp[rest] = min(dp[rest], dp[rest - prices[index]] *
                                             (1.0 - probability[index]));
            }
        }
    }

    return 1.0 - dp[n];
}

int main(int argc, char const* argv[]) {
    vector<int> prices = {4, 5, 6};
    vector<double> probability = {0.1, 0.2, 0.3};
    int n = 10;

    double res = backpackIX(n, prices, probability);
    cout << res << endl;

    double ans = dp(n, prices, probability);
    cout << ans << endl;

    double answer = optimizeDp(n, prices, probability);
    cout << answer << endl;

    return 0;
}