#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/89/
int kSum(vector<int>& a, int k, int target) {
    if (a.empty() || k > a.size()) {
        return 0;
    }

    int N = a.size();
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(k + 1, vector<int>(target + 1)));
    dp[N][0][0] = 1;
    for (int index = N - 1; index >= 0; index--) {
        for (int kNum = 0; kNum <= k; kNum++) {
            for (int rest = 0; rest <= target; rest++) {
                dp[index][kNum][rest] = dp[index + 1][kNum][rest];

                if (kNum > 0 && rest - a[index] >= 0) {
                    dp[index][kNum][rest] +=
                        dp[index + 1][kNum - 1][rest - a[index]];
                }
            }
        }
    }

    return dp[0][k][target];
}

