#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/136/
void process(string str, vector<vector<bool>>& dp) {
	int N = str.size();
	dp[N - 1][N - 1] = true;

	for (int i = 0; i < N - 1; i++) {
		dp[i][i] = true;
		dp[i][i + 1] = str.at(i) == str.at(i + 1) ? true : false;
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = i + 2; j < N; j++) {
			if (str.at(i) == str.at(j)) {
				dp[i][j] = dp[i + 1][j - 1];
			}
		}
	}
}

void solution(string str, int start, vector<vector<string>>& res, vector<string>& temp, vector<vector<bool>>& helpDp) {
	if (start >= str.size()) {
		res.push_back(temp);
	}
	for (int i = start; i < str.size(); i++) {
		if (helpDp[start][i]) {
			temp.push_back(str.substr(start, i + 1 - start));
			solution(str, i + 1, res, temp, helpDp);
			temp.pop_back();
		}
	}
}


vector<vector<string>> partition(string& s) {
	vector<vector<string>> res;
	if (s.empty()) {
		return res;
	}

	int N = s.size();
	vector<vector<bool>> helpDp(N, vector<bool>(N, false));
	process(s, helpDp);

	vector<string> temp;
	solution(s, 0, res, temp, helpDp);

	return res;
}

int main() {
	string str = "a";
	vector<vector<string>> res = partition(str);
	for (int i = 0; i < res.size(); i++) {
		for (string x : res[i]) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}