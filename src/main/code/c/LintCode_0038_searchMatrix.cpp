#include<iostream>
#include<vector>

using namespace std;

// https://www.lintcode.com/problem/38/description

int searchMatrix__0038(vector<vector<int>>& matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}

	int N = matrix.size();
	int M = matrix[0].size();

	int x = 0; int y = M - 1;

	int count = 0;
	while (x < N && y >= 0) {
		if (matrix[x][y] > target) {
			y--;
		}
		else if (matrix[x][y] < target) {
			x++;
		}
		else {
			count++;
			y--;
			x++;
		}
	}

	return count;
}

