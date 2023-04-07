#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int dp[maxn][maxn];
int dim[maxn];


int matrixChainOrder(int n) {
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + dim[i]*dim[k+1]*dim[j+1]);
            }
        }
    }
    return dp[0][n-1];
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> dim[i] >> dim[i+1];
    int ans = matrixChainOrder(n-1);
    cout << "Minimum number of scalar multiplications: " << ans << endl;
    return 0;
}