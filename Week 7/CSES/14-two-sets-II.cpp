#include <bits/stdc++.h>
using namespace std;


int countWays(int n) {
    int sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        return 0;
    }
    int target = sum / 2;
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }
    return dp[target];
}


int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;
    int ways = countWays(n);
    cout << "The number of ways to divide numbers 1 to " << n << " into two sets of equal sum is: " << ways << endl;
    return 0;
}