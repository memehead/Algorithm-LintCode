#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/392/
long long houseRobber(vector<int>& a) {
	if (a.empty()) {
		return 0;
	}
	int N = a.size();
	if (N == 1) {
		return a[0];
	}
	if (N == 2) {
		return a[0] >= a[1] ? a[0] : a[1];
	}

	long long pre = a[0];
	long long next = a[0] >= a[1] ? a[0] : a[1];
	long long cur = 0;
	long long ans = max(pre, next);

	for (int i = 2; i < N; i++) {
		cur = max(next, pre + a[i]);
		ans = max(ans, cur);
		pre = next;
		next = cur;
	}

	return ans;
}

int main() {

	vector<int> array = { 5,2,1,3 };
	long long res = houseRobber(array);
	cout << res << endl;

	return 0;
}