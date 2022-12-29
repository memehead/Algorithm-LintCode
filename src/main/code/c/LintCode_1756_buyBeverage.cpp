#include<iostream>

using namespace std;

// https://www.lintcode.com/problem/1756
int buyBeverage(int budget, int cost, int exchange) {
	if (budget < cost || exchange == 1) {
		return 0;
	}

	int res = 0;

	int buy = budget / cost;
	res += buy;

	int add = buy;
	int costIntegral = 0;

	while ((add / exchange) > 0) {
		costIntegral = add % exchange;
		add /= exchange;
		res += add;

		add += costIntegral;
	}

	return res;
}
