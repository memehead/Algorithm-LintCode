#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/8
void reverse(vector<char>&s, int L, int R) {
    while (L < R) {
        char temp = s[L];
        s[L++] = s[R];
        s[R--] = temp;
    }
}

void rotateString(vector<char>& s, int offset) {
    if (s.empty() || offset == 0 || offset % s.size() == 0) {
        return;
    }
    int N = s.size();
    offset = offset % N;

    reverse(s, 0, N - offset - 1);
    reverse(s,  N - offset, N - 1);
    reverse(s, 0, N - 1);
}