#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/161
void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty() || matrix.size() != matrix[0].size()) {
        return;
    }

    int N = matrix.size();
    int leftUpX = 0;
    int leftUpY = 0;

    int rightLowerX = N - 1;
    int rightLowerY = N - 1;

    while (leftUpX < rightLowerX) {
        for (int i = 0; i < rightLowerX - leftUpX; i++) {
            int temp = matrix[leftUpX][leftUpY + i];
            matrix[leftUpX][leftUpY + i] = matrix[rightLowerX - i][leftUpY];
            matrix[rightLowerX - i][leftUpY] =  matrix[rightLowerX][rightLowerY - i];
            matrix[rightLowerX][rightLowerY - i] = matrix[leftUpX + i][rightLowerY];
            matrix[leftUpX + i][rightLowerY] = temp;
        }

        leftUpX++;
        leftUpY++;
        rightLowerX--;
        rightLowerY--;
    }
}