#include <bits/stdc++.h>
using namespace std;


int minCoins(vector<int>& coins, int x) {
    int n = coins.size();
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i-coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
    }
    return dp[x];
}


int main() {
    int n, x;
    cout << "Enter the number of coins: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the values of the coins: ";
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << "Enter the sum of money to produce: ";
    cin >> x;
    int numCoins = minCoins(coins, x);
    if (numCoins == INT_MAX) {
        cout << "It is not possible to produce the sum of money" << endl;
    } else {
        cout << "The minimum number of coins needed to produce the sum of money is " << numCoins << endl;
    }
    return 0;
}