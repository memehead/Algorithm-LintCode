#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/396/description
bool firstWillWin(vector<int>& values) {
    if (values.empty() || values.size() < 2) {
        return true;
    }

    int N = values.size();
    vector<vector<int>> firstDp(N, vector<int>(N));
    vector<vector<int>> secondDp(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        firstDp[i][i] = values[i];
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            firstDp[i][j] = max(values[i] + secondDp[i + 1][j],
                values[j] + secondDp[i][j - 1]);
            secondDp[i][j] = min(firstDp[i + 1][j], firstDp[i][j - 1]);
        }
    }

    return firstDp[0][N - 1] >= secondDp[0][N - 1];
}
