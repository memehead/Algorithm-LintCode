#include<iostream>
#include<vector>

using namespace std;

// https://www.lintcode.com/problem/149

int maxProfit_0149(vector<int>& prices) {
	if (prices.empty() || prices.size() < 2) {
		return 0;
	}
	int minBuy = prices[0];
	int maxProfit = 0;

	for (int i = 1; i < prices.size(); i++) {
		maxProfit = max(maxProfit, prices[i] - minBuy);
		minBuy = min(minBuy, prices[i]);
	}
	
	return maxProfit;
}