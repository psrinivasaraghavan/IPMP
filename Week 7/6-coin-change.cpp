#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int dp[maxn], coins[maxn];


int coinChange(int amount, int n) {
    dp[0] = 1;
    for (int i = 1; i <= amount; i++) {
        dp[i] = 0;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] += dp[i-coins[j]];
            }
        }
    }
    return dp[amount];
}


int main() {
    int n, amount;
    cin >> n >> amount;
    for (int i = 0; i < n; i++) cin >> coins[i];
    int ans = coinChange(amount, n);
    cout << "Number of ways to make change: " << ans << endl;
    return 0;
}