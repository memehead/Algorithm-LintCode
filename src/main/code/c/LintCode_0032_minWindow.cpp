#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/32
string minWindow(string& source, string& target) {
    if (source.empty() || target.empty() || source.size() < target.size()) {
        return "";
    }

    unordered_map<char, int> map;
    int all = target.size();
    for (int i = 0; i < all; i++) {
        if (map.find(target.at(i)) != map.end()) {
            map[target.at(i)]++;
        } else {
            map[target.at(i)] = 1;
        }
    }
    
    string ans = "";
    int L = 0;
    int R = 0;
    int N = source.size();
    int minLen = INT_MAX;

    while (R < N) {
        map[source[R]]--;
        if (map[source[R]] >= 0) {
            all--;
        }
        if (all == 0) {
            while (map[source[L]] < 0) {
                map[source[L++]]++;
            }

            if (minLen > R - L + 1) {
                minLen = R - L + 1;
                ans = source.substr(L, minLen);
            }
            all++;
            map[source[L++]]++;
        }
        R++;
    }

    return ans;
}