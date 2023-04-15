#include <iostream>
using namespace std;


int countWays(int n) {
    int dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}


int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The number of ways to construct sum " << n << " is " << countWays(n) << ".\n";
    return 0;
}
