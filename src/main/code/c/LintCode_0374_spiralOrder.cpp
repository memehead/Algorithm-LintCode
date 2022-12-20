#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/374
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty() || matrix[0].empty()) {
        return ans;
    }
    int N = matrix.size();
    int M = matrix[0].size();
    
    int leftUpX = 0;
    int leftUpY = 0;
    int rightLowerX = N - 1;
    int rightLowerY = M - 1;
    while (leftUpX <= rightLowerX && leftUpY <= rightLowerY) {
        if (leftUpX == rightLowerX) {
            for (int i = leftUpY; i <= rightLowerY; i++) {
                ans.push_back(matrix[leftUpX][i]);
            }
            break;
        }

        if (leftUpY == rightLowerY) {
            for (int i = leftUpX; i <= rightLowerX; i++) {
                ans.push_back(matrix[i][leftUpY]);
            }
            break;
        }

        for (int i = 0; i < rightLowerY - leftUpY; i++) {
            ans.push_back(matrix[leftUpX][leftUpY + i]);
        }

        for (int i = 0; i < rightLowerX - leftUpX; i++) {
            ans.push_back(matrix[leftUpX + i][rightLowerY]);
        }

        for (int i = 0; i < rightLowerY - leftUpY; i++) {
            ans.push_back(matrix[rightLowerX][rightLowerY - i]);
        }

        for (int i = 0; i < rightLowerX - leftUpX; i++) {
            ans.push_back(matrix[rightLowerX - i][leftUpY]);
        }

        leftUpX++;
        leftUpY++;
        rightLowerX--;
        rightLowerY--;
    }

    return ans;
}