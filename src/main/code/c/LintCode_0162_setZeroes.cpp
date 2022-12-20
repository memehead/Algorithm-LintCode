#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/162
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }

    int N = matrix.size();
    int M = matrix[0].size();

    bool rowHaveZero = false;
    for (int i = 0; i < M; i++) {
        if (matrix[0][i] == 0) {
            rowHaveZero = true;
            break;
        }
    }

    bool colHaveZero = false;
    for (int i = 0; i < N; i++) {
        if (matrix[i][0] == 0) {
            colHaveZero = true;
            break;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < M; i++) {
        if (matrix[0][i] == 0) {
            for (int j = 0; j < N; j++) {
                matrix[j][i] = 0;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    if (rowHaveZero) {
        for (int i =0; i < M; i++) {
            matrix[0][i] = 0;
        }
    }

    if (colHaveZero) {
        for (int i = 0; i < N; i++) {
            matrix[i][0] = 0;
        }
    }
}