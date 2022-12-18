#include<iostream>
#include<vector>
using namespace std;

// https://www.lintcode.com/problem/116

bool canJump(vector<int>& a) {
	if (a.empty()) {
		return false;
	}
	
	//±ﬂΩÁ¥¶¿Ì
	if (a.at(0) == 0) {
		return a.size() == 1;
	}

	int maxDistance = a[0];
	bool res = false;
	for (int i = 1; i < a.size(); ++i) {
		if (maxDistance >= a.size() - 1) {
			res = true;
			break;
		}

		if (i > maxDistance) {
			return false;
		}

		maxDistance = max(maxDistance, i + a[i]);
	}
	
	return res;
}