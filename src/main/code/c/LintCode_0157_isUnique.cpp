#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/157/
bool isUnique(string& str) {
    if (str.empty() || str.size() < 2) {
        return true;
    }

    vector<int> map(128);

    int N = str.size();
    for (int i = 0; i < N; i++) {
        if (map[str.at(i)] != 0) {
            return false;
        } else {
            map[str.at(i)]++;
        }
    }

    return true;
}