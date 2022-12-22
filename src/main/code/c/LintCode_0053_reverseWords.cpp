#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/53
string reverseWords(string& s) {
    if (s.empty()) {
        return s;
    }

    stack<string> stack;
    int N = s.size();
    int L = 0;
    int R = 0;

    while (R < N) {
        while (R < N && s.at(R) == ' ') {
            R++;
        }
        if (R >= N) {
            break;
        }
        L = R;
        while (R < N && s.at(R) != ' ') {
            R++;
        }
        stack.push(s.substr(L, R - L));
    }

    string res;

    while (!stack.empty()) {
        res.append(stack.top());
        stack.size() != 1 ? res.append(" ") : res.append("");
        stack.pop();
    }

    return res;
}