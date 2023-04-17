#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int dp[MAXN][MAXN];


int main() {
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
    cout << dp[n][m] << endl;
    return 0;
}