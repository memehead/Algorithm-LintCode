#include<iostream>
using namespace std;

// https://www.lintcode.com/problem/1870

int stringCount(string& str) {
	if (str.empty()) {
		return 0;
	}
	int N = str.size();
	int L = 0; 
	int R = 0;

	int count = 0;
	while (R < N) {
		while (L < N && str.at(L) != '0') {
			L++;
		}
		if (L >= N) {
			break;
		}
		
		R = L;
		while (R < N && str.at(R) == '0') {
			R++;
		}

		count += (R - L)* (R - L + 1) / 2;
		L = R;
	}

	return count;
}