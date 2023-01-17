#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/123/
bool process(vector<vector<char>>& board, int i, int j, string& word, int k) {
    if (k == word.size()) {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
        return false;
    }
    if (board[i][j] != word.at(k)) {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '.';
    bool ans = process(board, i + 1, j, word, k + 1) ||
               process(board, i - 1, j, word, k + 1) ||
               process(board, i, j + 1, word, k + 1) ||
               process(board, i, j - 1, word, k + 1);
    
    board[i][j] = temp;
    return ans;
}

bool exist(vector<vector<char>>& board, string& word) {
    if (board.empty() || board[0].empty() || word.empty()) {
        return false;
    }

    bool ans = false;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (process(board, i, j, word, 0)) {
                return true;
            }
        }
    }

    return ans;
}