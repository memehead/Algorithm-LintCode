#include<iostream>
#include<vector>

using namespace std;

// https://www.lintcode.com/problem/150

int maxProfit(vector<int>& prices) {
	if (prices.empty() || prices.size() < 2) {
		return 0;
	}

	int maxProfit = 0;

	for (int i = 1; i < prices.size(); i++) {
		maxProfit += (prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0);
	}

	return maxProfit;
}