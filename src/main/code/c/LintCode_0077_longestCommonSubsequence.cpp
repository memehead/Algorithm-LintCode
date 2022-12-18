#include<iostream>
#include<vector>
using namespace std;

// https://www.lintcode.com/problem/77

int longestCommonSubsequence(string& a, string& b) {
	if (a.empty() || b.empty()) {
		return 0;
	}

	int N = a.size();
	int M = b.size();

	vector<vector<int>> dp(N, vector<int>(M, 0));

	dp[0][0] = a.at(0) == b.at(0) ? 1 : 0;
	for (int i = 1; i < N; i++) {
		dp[i][0] = b.at(0) == a.at(i) ? 1 : dp[i - 1][0];
	}

	for (int i = 1; i < M; i++) {
		dp[0][i] = b.at(i) == a.at(0) ? 1 : dp[0][i - 1];
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			
			if (a.at(i) == b.at(j)) {
				//可以优化
				//dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
		
	return dp[N - 1][M - 1];
}