# include<iostream>
# include<vector>
using namespace std;

// https://www.lintcode.com/problem/110

int minPathSum(vector<vector<int>>& grid) {
	if (grid.empty() || grid[0].empty()) {
		return 0;
	}

	int N = grid.size();
	int M = grid[0].size();

	vector<vector<int>> dp(N, vector<int>(M, 0));

	dp[0][0] = grid[0][0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = grid[i][0] + dp[i - 1][0];
	}

	for (int i = 1; i < M; i++) {
		dp[0][i] = grid[0][i] + dp[0][i - 1];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
		}
	}

	return dp[N - 1][M - 1];
}