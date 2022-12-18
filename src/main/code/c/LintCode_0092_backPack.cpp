#include <iostream>
#include <vector>

using namespace std;

// https://www.lintcode.com/problem/92

int process(vector<int>& array, int index, int rest) {
	if (rest < 0) {
		return -1;
	}
	if (index == array.size()) {
		return 0;
	}

	int ans1 = process(array, index + 1, rest);

	int ans2 = process(array, index + 1, rest - array[index]);
	if (ans2 != -1) {
		ans2 += array[index];
	}

	return max(ans1, ans2);
}

// 暴力递归
int backPack(int m, vector<int>& a) {
	if (a.empty() || m <= 0) {
		return 0;
	}

	int N = a.size();
	return process(a, 0, m);
}


// 动态规划（可以进行空间压缩）
int backPack2(int m, vector<int>& a) {
	if (a.empty() || m <= 0) {
		return 0;
	}

	int N = a.size();
	vector<vector<int>> dp(N + 1, vector<int>(m + 1, 0));

	for (int index = N - 1; index >= 0; index--) {
		for (int rest = 1; rest <= m; rest++) {
			dp[index][rest] = dp[index + 1][rest];
			if (rest - a[index] >= 0) {
				dp[index][rest] = max(dp[index][rest], dp[index + 1][rest - a[index]] + a[index]);
			}
		}
	}

	return dp[0][m];
}