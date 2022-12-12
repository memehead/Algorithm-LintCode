#include<iostream>
using namespace std;
#include<vector>

// 暴力递归
int process(vector<int>& array1, vector<int>& array2, int index, int V) {
    if (index == array1.size()){
        return 0;
    }

    int p1 = process(array1, array2, index + 1, V);
    int p2 = 0;
    if (array1[index] <= V) {
        p2 = process(array1, array2, index + 1, V - array1[index]) + array2[index];
    }

    return max(p1, p2);
}

// 动态规划
int dp(vector<int>& array1, vector<int>& array2, int index, int V) {
    if (index == array1.size()){
        return 0;
    }
    int N = array1.size();

    int dp[N + 1][V + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = 0;
        }
    }

    for (int index = N - 1; index >= 0; index--) {
        for (int rest = 0; rest <= V; rest++) {
            dp[index][rest] = dp[index + 1][rest];
            if (rest - array1[index] >= 0) {
                dp[index][rest] =
                    max(dp[index][rest],
                        dp[index + 1][rest - array1[index]] + array2[index]);
            }
        }
    }

    return dp[0][V];
}

/* 
    01背包问题
 */
int main(int argc, char const *argv[])
{
    int N; int V;
    cin >> N >> V;
    vector<int> volumns(N);
    vector<int> values(N);

    for(int i = 0; i < N ; i++){
        cin >> volumns[i] >> values[i];
    }

    int result = dp(volumns, values, 0, V);

    cout << result << endl;

    return 0;
}
