#include <bits/stdc++.h>
using namespace std;


int maxCoins(int coins[], int n) {
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][i] = coins[i];
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (coins[i+1] >= coins[j]) dp[i][j] = coins[i] + dp[i+2][j];
            else dp[i][j] = coins[i] + dp[i+1][j-1];
            dp[i][j] = max(dp[i][j], coins[j] + dp[i][j-2]);
        }
    }
    return dp[0][n-1];
}


int main() {
    int coins[] = {8, 15, 3, 7}, n = sizeof(coins) / sizeof(coins[0]);
    cout << "The maximum number of coins that can be collected is " << maxCoins(coins, n) << endl;
    return 0;
}