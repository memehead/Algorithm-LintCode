
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.lintcode.com/problem/57/description

void twoSum(vector<int>& numbers, int left, int right, int target, vector<int>& ans, vector<vector<int>>& res) {
    if (left >= right) {
        return;
    }
    int L = left;
    int R = right - 1;
    while (L < R) {
        if ((numbers[L] + numbers[R]) > target) {
            R--;
        }
        else if ((numbers[L] + numbers[R]) < target) {
            L++;
        }
        else {
            if (L == left || numbers[L - 1] != numbers[L]) {
                ans.push_back(numbers[L]);
                ans.push_back(numbers[R]);
                res.push_back(ans);
                ans.pop_back();
                ans.pop_back();
            }
            L++;
            R--;
        }
    }
}


vector<vector<int>> threeSum(vector<int> &numbers) {
    vector<vector<int>> res;
    if (numbers.empty() || numbers.size() < 3) {
        return res;
    }
    sort(numbers.begin(), numbers.end());

    vector<int> ans;
    int R = numbers.size();
    for (int i = 0; i < R; i++) {
        if (i == 0 || numbers[i - 1] != numbers[i]) {
            ans.push_back(numbers[i]);
            twoSum(numbers, i + 1, R, -numbers[i], ans, res);
            ans.pop_back();
        }
    }

    return res;
}
