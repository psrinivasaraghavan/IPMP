#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1005;
const int MOD = 1e9+7;
int n, m, k;
int a[MAXN];
int dp[MAXN][MAXN];


int main() {
    cin >> n >> m;
    k = n - m;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;

        if (c == '?') {
            a[i] = 0;
            k++;
        } else {
            a[i] = c - '0';
        }
    }
    for (int j = 1; j <= m; j++) dp[0][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == 0 || a[i] == j) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n-k][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}