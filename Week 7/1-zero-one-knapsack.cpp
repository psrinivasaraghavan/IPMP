#include <bits/stdc++.h>
using namespace std;


int knapsack(vector<int>& profits, vector<int>& weights, int W) {
    int n = profits.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + profits[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int res = dp[n][W];
    int w = W;
    vector<int> items;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i-1][w]) {
            continue;
        }
        else {
            items.push_back(i-1);
            res -= profits[i-1];
            w -= weights[i-1];
        }
    }
    cout << "Items included in knapsack: ";
    for (int i = items.size()-1; i >= 0; i--) {
        cout << items[i] << " ";
    }
    cout << endl;
    return dp[n][W];
}


int main() {
    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int max_value = knapsack(profits, weights, W);
    cout << "Maximum profit: " << max_value << endl;
    return 0;
}
