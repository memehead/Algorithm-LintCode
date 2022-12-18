#include <iostream>
#include <vector>

using namespace std;

// https://www.lintcode.com/problem/151

int maxProfit(vector<int>& prices) {
	if (prices.empty() || prices.size() < 2) {
		return 0;
	}
	int N = prices.size();
	vector<vector<int>> dp(N, vector<int>(3, 0));

	for (int j = 1; j < 3; j++) {
		int best = max(dp[1][j - 1] - prices[1], dp[0][j - 1] - prices[0]);
		for (int i = 1; i < N; i++) {
			dp[i][j] = dp[i - 1][j];

			best = max(best, dp[i][j - 1] - prices[i]);
			dp[i][j] = max(dp[i][j], best + prices[i]);
		}
	}
	
	return dp[N - 1][2];
}