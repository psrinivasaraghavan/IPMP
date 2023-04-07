#include <bits/stdc++.h>
using namespace std;
const int MAXF = 1005, MAXE = 105;
int n, k, dp[MAXE][MAXF];


int eggDropping() {
    for (int i = 1; i <= k; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= n; j++) dp[1][j] = j;
    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][x - 1], dp[i][j - x]));
        }
    }
    return dp[k][n];
}


int main() {
    cout << "Enter the number of eggs: ";
    cin >> k;
    cout << "Enter the number of floors: ";
    cin >> n;
    cout << "Minimum number of trials required: " << eggDropping() << endl;
    return 0;
}