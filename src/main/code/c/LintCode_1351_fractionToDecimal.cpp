#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/1351/
string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        return "0";
    }
    string ans = "";
    int temp = numerator / denominator;
    ans.append(to_string(temp));
    int rest = numerator % denominator;

    if (rest != 0) {
        ans.append(".");
    }

    unordered_map<int, int> map;
    map[rest] = ans.size();
    int index = ans.size();
    while (rest != 0) {
        rest *= 10;
        temp = rest / denominator;
        ans.append(to_string(temp));
        rest %= denominator;
        if (map.find(rest) != map.end()) {
            ans.insert(map[rest], "(");
            ans.append(")");
            break;
        } else {
            map[rest] = ans.size();
        }
    }

    return ans;
}