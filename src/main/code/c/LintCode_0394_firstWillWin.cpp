#include <iostream>

using namespace std;

// https://www.lintcode.com/problem/394

bool firstWillWin_0394(int n) {
	if (n == 0) {
		return false;
	}
	if (n < 3) {
		return true;
	}

	return n % 3 != 0;
}