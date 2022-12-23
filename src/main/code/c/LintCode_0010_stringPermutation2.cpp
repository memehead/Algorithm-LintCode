#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/10
void swap(string& str, int i, int j) {
    char temp = str.at(i);
    str[i] = str.at(j);
    str[j] = temp;
}

void process(string& str, int index, vector<string>& res) {
    if (index == str.size()) {
        res.push_back(str);
        return;
    }
    vector<bool> dp(26);
    for (int i = index; i < str.size(); i++) {
        if (!dp[str.at(i) - 'a']) {
            dp[str.at(i) - 'a'] = true;
            swap(str, i, index);
            process(str, index + 1, res);
            swap(str, i, index);
        }
    }
}

vector<string> stringPermutation2(string& str) {
    vector<string> res;
    if (str.empty()) {
        res.push_back("");
        return res;
    }

    process(str, 0, res);

    return res;
}