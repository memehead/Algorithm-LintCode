#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/1332

int hammingWeight(int n) {
	int ans = 0;

	for (int i = 31; i >= 0; i--) {
		if (((n >> i) & 1) == 1) {
			ans++;
		}
	}

	return ans;
}