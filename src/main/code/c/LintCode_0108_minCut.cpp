#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/108/
void process(string str, vector<vector<bool>>& dp) {
    int N = str.size();
    dp[N - 1][N - 1] = true;

    for (int i = 0; i < N - 1; i ++) {
        dp[i][i] = true;
        dp[i][i + 1] = str.at(i) == str.at(i + 1) ? true : false;
    }

    for (int i = N - 2; i >= 0; i --) {
        for (int j = i + 2; j < N; j++) {
            if (str.at(i) == str.at(j)) {
                dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }
}

int minCut(string& s) {
    if (s.empty()) {
        return 0;
    }

    int N = s.size();
    vector<vector<bool>> helpDp(N, vector<bool>(N, false));
    process(s, helpDp);

    vector<int> dp(N + 1, INT_MAX);
    dp[N] = 0;

    for (int start = N - 1; start >= 0; start--) {
        for (int i = start; i < N; i++) {
            if (helpDp[start][i]) {
                int next = dp[i + 1];
                if (next != INT_MAX) {
                    next += 1;
                }
                dp[start] = min(next, dp[start]);
            }
        }
    }

    return dp[0] - 1;
}