#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/1538/
int process(vector<int>& cost, vector<int>& damage, int index, int rest) {
    if (index == cost.size()) {
        return 0;
    }

    int p1 = process(cost, damage, index + 1, rest);
    int p2 = 0;
    if ((rest >= cost[index])) {
        p2 = process(cost, damage, index + 1, rest - cost[index]) +
             damage[index];
    }

    return max(p1, p2);
}

// 暴力递归
bool cardGame(vector<int>& cost,
              vector<int>& damage,
              int totalMoney,
              int totalDamage) {
    if (cost.empty() || damage.empty() || cost.size() != damage.size()) {
        return false;
    }

    return process(cost, damage, 0, totalMoney) >= totalDamage;
}

// 动态规划
bool dp(vector<int>& cost,
        vector<int>& damage,
        int totalMoney,
        int totalDamage) {
    if (cost.empty() || damage.empty() || cost.size() != damage.size()) {
        return false;
    }

    int N = cost.size();
    vector<vector<int>> dp(N + 1, vector<int>(totalMoney + 1));
    for (int index = N - 1; index >= 0; --index) {
        for (int rest = 0; rest <= totalMoney; ++rest) {
            dp[index][rest] = dp[index + 1][rest];
            if (rest >= cost[index]) {
                dp[index][rest] =
                    max(dp[index][rest],
                        dp[index + 1][rest - cost[index]] + damage[index]);
            }
        }
    }

    return dp[0][totalMoney] >= totalDamage;
}

// 动态规划（空间压缩）
bool optimizeDp(vector<int>& cost,
                vector<int>& damage,
                int totalMoney,
                int totalDamage) {
    if (cost.empty() || damage.empty() || cost.size() != damage.size()) {
        return false;
    }

    int N = cost.size();
    vector<int> dp(totalMoney + 1);
    for (int index = N - 1; index >= 0; --index) {
        for (int rest = totalMoney; rest >= 0; --rest) {
            if (rest >= cost[index]) {
                dp[rest] =
                    max(dp[rest], dp[rest - cost[index]] + damage[index]);
            }
        }
    }

    return dp[totalMoney] >= totalDamage;
}

// 生成随机长度的数组
vector<int> generateRandomVector(int maxSize, int maxValue) {
    int N = rand() % (maxSize + 1);
    unordered_set<int> set;
    while (N != 0) {
        set.insert(rand() % (maxValue + 1) + 1);
        --N;
    }

    vector<int> array(N);
    auto it = set.begin();
    while (it != set.end()) {
        array.push_back(*it);
        ++it;
    }

    return array;
}

int main(int argc, char const* argv[]) {
    bool flag = false;
    for (int i = 0; i < 1000; ++i) {
        vector<int> cost = generateRandomVector(10, 10);
        vector<int> damage = generateRandomVector(10, 10);

        int totalMoney = rand() % 20;
        int totalDamage = rand() % 20;

        int res = cardGame(cost, damage, totalMoney, totalDamage);
        int ans = dp(cost, damage, totalMoney, totalDamage);
        int answer = optimizeDp(cost, damage, totalMoney, totalDamage);

        if (res != ans || ans != answer || res != answer) {
            cout << res << endl;
            cout << ans << endl;
            cout << answer << endl;

            flag = true;
            break;
        }
    }

    cout << (!flag ? "Nice!" : "Fuck!") << endl;

    return 0;
}