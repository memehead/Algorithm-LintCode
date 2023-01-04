#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/425/description
const vector<vector<string>> dict = {
    {"a", "b", "c"}, {"d", "e", "f"},
    {"g", "h", "i"}, {"j", "k", "l"},
    {"m", "n", "o"}, {"p", "q", "r", "s"},
    {"t", "u", "v"}, {"w", "x", "y", "z"} };

void process(string str, int index, vector<string>& ans, vector<string>& res) {
    if (index == str.size() && ans.size() == str.size()) {
        string temp = "";
        for (string x : ans) {
            temp.append(x);
        }
        res.push_back(temp);
        return;
    }
    for (int i = index; i < str.size(); i++) {
        vector<string> array = dict[str.at(i) - '2'];
        for (string x : array) {
            ans.push_back(x);
            process(str, i + 1, ans, res);
            ans.pop_back();
        }
    }
}

vector<string> letterCombinations(string &digits) {
    vector<string> res;
    if (digits.empty()) {
        return res;
    }

    vector<string> ans;
    process(digits, 0, ans, res);

    return res;
}
