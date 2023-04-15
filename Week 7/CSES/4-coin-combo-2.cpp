#include <bits/stdc++.h>
using namespace std;


int countWays(vector<int>& coins, int x) {
    int n = coins.size();
    vector<int> dp(x+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] += dp[j-coins[i]];
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
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Enter the sum of money to produce: ";
    cin >> x;
    int numWays = countWays(coins, x);
    cout << "The number of distinct ordered ways to produce the sum of money is " << numWays << endl;
    return 0;
}