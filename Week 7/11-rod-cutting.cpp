#include <bits/stdc++.h>
using namespace std;


int max_profit(int n, vector<int>& prices) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        for (int j = 1; j <= i; j++) {
            max_val = max(max_val, prices[j] + dp[i - j]);
        }
        dp[i] = max_val;
    }
    return dp[n];
}


int main() {
    int n;
    cin >> n;
    vector<int> prices(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> prices[i];
    int max_profit_val = max_profit(n, prices);
    cout << "Maximum Profit: " << max_profit_val << endl;
    return 0;
}