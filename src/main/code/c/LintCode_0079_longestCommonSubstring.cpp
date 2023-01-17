#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/79
int longestCommonSubstring(string& a, string& b) {
    if (a.empty() || b.empty()) {
        return 0;
    }
    int N = a.size();
    int M = b.size();

    vector<vector<int>> dp(N, vector<int>(M));

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (a[0] == b[i]) {
            dp[0][i] = 1;
        }
        ans = max(ans, dp[0][i]);
    }

    for (int i = 0; i < N; i++) {
        if (b[0] == a[i]) {
            dp[i][0] = 1;
        }
        ans = max(ans, dp[i][0]);
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
             ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}