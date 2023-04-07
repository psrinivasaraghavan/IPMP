#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;


int main() {
    int n, m;
    int a[maxn][maxn];
    int dp[maxn][maxn];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = a[i][j];
            } else if (a[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans << endl;
    return 0;
}