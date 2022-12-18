#include<iostream>
#include<vector>

using namespace std;

// https://www.lintcode.com/problem/28/description

int searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}

	int N = matrix.size();
	int M = matrix[0].size();

	int x = 0;
	int y = M - 1;

	while (x < N && y >= 0) {
		if (matrix[x][y] > target) {
			y--;
		}
		else if (matrix[x][y] < target) {
			x++;
		}
		else {
			return true;
		}
	}

	return false;
}


bool binarySearch(vector<int>& array, int target) {
	int L = 0; int R = array.size() - 2;

	while (L <= R) {
		int middle = L + ((R - L) >> 1);
		if (array[middle] > target) {
			R = middle - 1;
		}
		else if (array[middle] < target) {
			L = middle + 1;
		}
		else {
			return true;
		}
	}

	return false;
}

/// <summary>
/// 方法2快
/// </summary>
/// <param name="matrix"></param>
/// <param name="target"></param>
/// <returns></returns>
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}

	int N = matrix.size();
	int M = matrix[0].size();

	int x = 0;

	while (x < N) {
		if (matrix[x][M - 1] > target) {
			// 二分
			return binarySearch(matrix[x], target);
		}
		else if (matrix[x][M - 1] < target) {
			x++;
		}
		else {
			return true;
		}
	}

	return false;
}
