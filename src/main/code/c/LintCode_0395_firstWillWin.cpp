#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/395/

bool firstWillWin(vector<int> &values) {
    if (values.empty() || values.size() < 3) {
        return true;
    }

    int N = values.size();

    vector<int> firstDp(N + 1);
    vector<int> secondDp(N + 1);

    firstDp[N - 1] = values[N - 1];
    firstDp[N - 2] = values[N - 1] + values[N - 2];

    for (int index = N - 3; index >= 0; index--) {
        firstDp[index] = max(values[index] + secondDp[index + 1], values[index] + values[index + 1] + secondDp[index + 2]);
        secondDp[index] = min(firstDp[index + 1], firstDp[index + 2]);
    }

    return firstDp[0] >= secondDp[0];
}