#include <iostream>
#include <vector>

using namespace std;

// https://www.lintcode.com/problem/84

vector<int> singleNumberIII(vector<int>& a) {
	vector<int> res;
	if (a.empty() || a.size() < 2) {
		return res;
	}

	if (a.size() == 2) {
		return a;
	}

	int eor = 0;
	for (int i = 0; i < a.size(); i++) {
		eor ^= a[i];
	}

	int flag = eor & (~eor + 1);

	int partNum = 0;
	for (int i = 0; i < a.size(); i++) {
		// 要与0比较，不是1
		if ((a[i] & flag) == 0) {
			partNum ^= a[i];
		}
	}

	res.push_back(partNum);
	res.push_back(eor ^ partNum);
	return res;
}